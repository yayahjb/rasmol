import glob, os, re

os.makedirs("out", exist_ok=True)

def remap(n):
    """KOI8-R code -> cp1251 code, or None if cp1251 has no such character."""
    if n < 128:
        return n
    try:
        return bytes([n]).decode("koi8-r").encode("cp1251")[0]
    except (UnicodeEncodeError, UnicodeDecodeError):
        return None

def convert(src, dst):
    lines = open(src, encoding="latin-1").read().split("\n")
    i, header = 0, []
    while not lines[i].startswith("CHARS "):
        header.append(lines[i]); i += 1
    i += 1
    glyphs = []
    while i < len(lines):
        if lines[i].startswith("STARTCHAR"):
            blk = []
            while True:
                blk.append(lines[i])
                done = lines[i].startswith("ENDCHAR")
                i += 1
                if done: break
            glyphs.append(blk)
        else:
            i += 1

    # header: font name, charset properties, default char
    for k, l in enumerate(header):
        if l.startswith("FONT "):
            header[k] = re.sub(r"-KOI8-R\s*$", "-microsoft-cp1251", l)
        elif l.startswith("CHARSET_REGISTRY"):
            header[k] = 'CHARSET_REGISTRY "microsoft"'
        elif l.startswith("CHARSET_ENCODING"):
            header[k] = 'CHARSET_ENCODING "cp1251"'
        elif l.startswith("DEFAULT_CHAR"):
            m = remap(int(l.split()[1]))
            header[k] = "DEFAULT_CHAR %d" % (m if m is not None else 32)

    out = []
    for blk in glyphs:
        for k, l in enumerate(blk):
            if l.startswith("ENCODING"):
                n = int(l.split()[1])
                m = remap(n) if n >= 0 else None
                if m is None:
                    blk = None
                else:
                    blk[k] = "ENCODING %d" % m
                break
        if blk:
            out.append((m, blk))
    out.sort(key=lambda t: t[0])

    with open(dst, "w", encoding="latin-1") as f:
        f.write("\n".join(header) + "\n")
        f.write("CHARS %d\n" % len(out))
        for _, blk in out:
            f.write("\n".join(blk) + "\n")
        f.write("ENDFONT\n")
    return len(out)

for src in sorted(glob.glob("*/*.bdf")):
    dst = os.path.join("out", os.path.basename(src))
    print(src, "->", dst, convert(src, dst), "glyphs")

