

  { "Syntaxe de commande incorrecte!\n",               ErrSyntax,   French ,0},
  { "Valeur du param�tre trop grande!\n",              ErrBigNum,   French ,0},
  { "Valeur du param�tre incorrecte!\n",               ErrBadOpt,   French ,0},
  { "Nom du param�tre incorrect!\n",                   ErrParam,    French ,0},
  { "Un nom de fichier est attendu!\n",                ErrFilNam,   French ,0},
  { "Base de donn�es de mol�cules charg�e!\n",         ErrBadLoad,  French ,0},
  { "Une valeur enti�re est attendue!\n",              ErrNotNum,   French ,0},
  { "Manque une virgule de s�paration!\n",             ErrNotSep,   French ,0},
  { "Manque un crochet fermant ']'!\n",                ErrNotBrac,  French ,0},
  { "Aucune couleur n'a �t� sp�cifi�e!\n",             ErrNoCol,    French ,0},
  { "Couleur incorrecte ou inconnue!\n",               ErrColour,   French ,0},
  { "Argument de commande invalide!\n",                ErrBadArg,   French ,0},
  { "Erreur de syntaxe dans l'expression!\n",          ErrBadExpr,  French ,0},
  { "Une parenth�se fermante ')' est attendue!\n",     ErrParen,    French ,0},
  { "La pile de commande est trop profonde!\n",        ErrScript,   French ,0},
  { "Une parenth�se ouvrante '(' est attendue!\n",     ErrFunc,     French ,0},
  { "Nom d'atome invalide ou erron�!\n",               ErrSetName,  French ,0},
  { "M�moire insuffisante pour d�finir l'ensemble!\n", ErrBadSet,   French ,0},
  { "Commande d�sactiv�e dans le fichier de script!\n", ErrInScrpt,  French ,0},
  { "Commande invalide (le serait seulement dans un script)!\n", ErrOutScrpt, French ,0},
  { "Base de donn�es de mol�cules non charg�e!\n",     ErrBadMolDB, French ,0},
  { "Liaison de tourner non choisi!\n",                ErrNoBond,   French ,0},
  { "Erreur: Fichier '",                               StrErrFile,  French ,0},
  { "' non trouv�!\n\n",                               StrNotFnd,   French ,0},
  { "Erreur: Format de compression non reconnu!\n\n",  StrCFmt,     French ,0},
  { "Erreur: Impossible de d�compresser le fichier!\n\n", StrDcmp,     French ,0},
  { "Ligne de command de script trop longue!\n",       StrSLong,    French ,0},
  { "Erreur de commande: M�moire inuffisante!\n",      StrSMem,     French ,0},
  { "Impossible de trouver le fichier d'aide sur RasMol!\n",  StrHFil,     French ,0},
  { "Requ�te d'aide th�matique ambig�e!\n",            StrHTop,     French ,0},
  { "Pas d'aide disponible sur le th�me requis!\n",    StrHNone,    French ,0},
  { "Erreur de commande: Impossible de r�ouvrir le fichier d'aide!\n",   StrHROpn,    French ,0},
  { "Cha�ne de caract�res non termin�e!\n",            StrCTerm,    French ,0},
  { "Cha�ne de caract�res trop longue!\n",             StrCLong,    French ,0},
  { "Nombre � virgule flottante invalide!\n",          StrFNum,     French ,0},
  { "Aucun atome � recentrer!\n",                      StrCent,     French ,0},
  { "Impossible de copier le porte-papiers!\n",        StrCClip,    French ,0},
  { "Impossible d'ouvrir le fichier de points '",      StrDFile,    French ,0},
  { "Avertissement: Aucune imprimante disponible!\n",  StrNPrint,   French ,0},
  { "Cellule Unit�",                                   StrUCell,    French ,0},
  { "Groupe Spatial",                                  StrSGroup,   French ,0},
  { "Pas de donn�es de sym�trie du cristal!\n",        StrSymm,     French ,0},
  { "Commande non reconnue!\n",                        StrUnrec,    French ,0},
  { "Avertissement: Reste de la commande ignor�e!\n",  StrIgnore,   French ,0},
  { "Avertissement: Command indirecte trop longue!\n", StrRCLong,   French ,0},
  { "Impossible d'ouvrir le fichier de script file '", StrSFile,    French ,0},
  { "Identificateur trop long!\n",                     StrILong,    French ,0},
  { "Nom de la mol�cule .... ",                        StrMolNam,   French ,0},
  { "Classification ........ ",                        StrClass,    French ,0},
  { "Structure Secondaire... ",                        StrSecSt,    French ,0},
  { "Non assign�\n",                                   StrNoAsmt,   French ,0},
  { "Registre PDB\n",                                  StrPDBRec,   French ,0},
  { "Calcul�\n",                                       StrCalc,     French ,0},
  { "Code de Base de Donn�es ",                        StrDBCode,   French ,0},
  { "Technique exp�rim.  ... ",                        StrExpTec,   French ,0},
  { "Nombre de Cha�nes ..... ",                        StrNumChn,   French ,0},
  { "Nombre de Groupes ..... ",                        StrNumGrp,   French ,0},
  { "Nombre d'Atomes ....... ",                        StrNumAtm,   French ,0},
  { "Nombre de Liaisons .... ",                        StrNumBnd,   French ,0},
  { "Nombre de Ponts ....... ",                        StrNumBrg,   French ,0},
  { "Nombre de Liaisons-H .. ",                        StrNumHbd,   French ,0},
  { "Nombre d'H�lices ...... ",                        StrNumHel,   French ,0},
  { "Nombre de Tresses ..... ",                        StrNumStrnd, French ,0},
  { "Nombre de Tours ....... ",                        StrNumTrn,   French ,0},
  { "Allocation m�moire d�faillante",                  StrMalloc,   French ,0},
  { "Nouveaux r�sidus trop nombreux",                  StrXSRes,    French ,0},
  { "Nouveaux type d'atomes trop nombreux",            StrXSAtyp,   French ,0},
#ifndef MSWIN
  { "Ouvrir...",                                       StrMOpen,    French ,0},
  { "Sauver sous...",                                  StrMSaveAs,  French ,0},
  { "Fermer",                                          StrMClose,   French ,0},
  { "",                                                StrMEmpty,   French ,0},
#ifdef APPLEMAC
  { "Configuration des Pages",                         StrMPSetup,  French ,0},
  { "Imprimer",                                        StrMPrint,   French ,0},
  { "Quitter",                                         StrMExit,    French ,0},
#else
  { "Terminer",                                        StrMExit,    French ,0},
#endif
  { "Fil",                                             StrMWirefr,  French ,0},
  { "Squelette",                                       StrMBackbn,  French ,0},
  { "B�tons",                                          StrMSticks,  French ,0},
  { "Espace r��l occup�",                              StrMSpacefl, French ,0},
  { "Boules et B�tons",                                StrMBallStk, French ,1},
  { "Rubans",                                          StrMRibbons, French ,0},
  { "Tresses",                                         StrMStrands, French ,0},
  { "Ebauches",                                        StrMCartoon, French ,5},
  { "Surface Mol�cular",                               StrMMolSurf, French ,8},
  { "Monochrome",                                      StrMMonochr, French ,0},
  { "CPK",                                             StrMCPK,     French ,0},
  { "Forme",                                           StrMShapely, French ,0},
  { "Groupe",                                          StrMGroup,   French ,0},
  { "Cha�ne",                                          StrMChain,   French ,1},
  { "Temp�rature",                                     StrMTemp,    French ,0},
  { "Structure",                                       StrMStruct,  French ,0},
  { "Utilisateur",                                     StrMUser,    French ,0},
  { "Mod�le",                                          StrMModel,   French ,2},
  { "Alt",                                             StrMAlt,     French ,0},
  { "Vision en Coupe",                                 StrMSlab,    French ,10},
  { "Hydrog�nes",                                      StrMHydr,    French ,1},
  { "H�t�roatomes",                                    StrMHet,     French ,0},
  { "Reflets",                                         StrMSpec,    French ,0},
  { "Ombres",                                          StrMShad,    French ,0},
  { "St�r�o",                                          StrMStereo,  French ,0},
  { "Labels",                                          StrMLabel,   French ,0},
  { "D�sactiver Choix",                                StrMPOff,    French ,0},
  { "Activer Identification",                          StrMPIdent,  French ,8},
  { "Activer Distance",                                StrMPDist,   French ,8},
  { "Activer Moniteur",                                StrMPMon,    French ,8},
  { "Activer Angle",                                   StrMPAng,    French ,8},
  { "Activer Torsion",                                 StrMPTrsn,   French ,8},
  { "Activer Label",                                   StrMPLabl,   French ,8}, 
  { "Activer Centre",                                  StrMPCent,   French ,8},
  { "Activer Coord",                                   StrMPCoord,  French ,8},
  { "Activer Liaison",                                 StrMPBond,   French ,9},
  { "Tourner Liaison",                                 StrMRBond,   French ,10},
  { "Tourner Mol�cule",                                StrMRMol,    French ,9},
  { "Tourner Globalement",                             StrMRAll,    French ,8},
  { "BMP ...",                                         StrMBMP,     French ,0},  
  { "GIF ...",                                         StrMGIF,     French ,0},  
  { "IRIS RGB ...",                                    StrMIRGB,    French ,5}, 
  { "PPM ...",                                         StrMPPM,     French ,2},  
  { "Sun Raster...",                                   StrMSRast,   French ,0},  
  { "PostScript...",                                   StrMPostscr, French ,0},  
  { "PICT...",                                         StrMPICT,    French ,1},  
  { "Vector PS ...",                                   StrMVECPS,   French ,0},  
  { "Molscript ...",                                   StrMMSCR,    French ,1},  
  { "Kinemage ...",                                    StrMKine,    French ,0},  
  { "POVRay 3 ...",                                    StrMPOVRAY,  French ,2},  
  { "VRML ...",                                        StrMVRML,    French ,3},  
  { "Ramachandran ...",                                StrMRPP,     French ,3},  
  { "Raster3D ...",                                    StrMR3D,     French ,6},  
  { "RasMol Script ...",                               StrMSCR,     French ,8},  
  { "A propos de RasMol...",                           StrMAbout,   French ,0},
  { "Manual utilisateur...",                           StrMUserM,   French ,0},
  { "Annuler",                                         StrMUndo,    French ,0},
  { "Couper",                                          StrMCut,     French ,0},
  { "Copier",                                          StrMCopy,    French ,1},
  { "Coller",                                          StrMPaste,   French ,2},
#ifdef APPLEMAC
  { "Effacer",                                         StrMClear,   French ,0},
#else
  { "D�truire",                                        StrMDelete,  French ,0},
#endif
  { "S�lectionner tout",                               StrMSelAll,  French ,0},
  { "Fichier",                                         StrMFile,    French ,0},
  { "Editer",                                          StrMEdit,    French ,0},
  { "Montrer",                                         StrMDisplay, French ,0},
  { "Couleurs",                                        StrMColour,  French ,0},
  { "Options",                                         StrMOpt,     French ,0},
  { "Configuration",                                   StrMSettings,French ,3},
  { "Exporter",                                        StrMExport,  French ,1},
#ifdef APPLEMAC
  { "Fen�tre",                                         StrMWindow,  French ,0},
#endif
  { "Aide",                                            StrMHelp,    French ,0},
#ifdef APPLEMAC
  { "Fen�tre Principale",                              StrMMainWin,  French ,0},
  { "Ligne de Commande",                               StrMCmndLin,  French ,0},
#endif
#else
  { "&Ouvrir ...",                                     StrMOpen,    French ,0},
  { "&Information",                                    StrMInfo,    French ,0},
  { "&Fermer",                                         StrMClose,   French ,0},
  { "Im&primer",                                       StrMPrint,   French ,2},
  { "&Configuration des Pages",                        StrMPSetup,  French ,0},
  { "&Terminer",                                       StrMExit,    French ,0},
  { "&Fil",                                            StrMWirefr,  French ,0},
  { "&Squelette",                                      StrMBackbn,  French ,0},
  { "&B�tons",                                         StrMSticks,  French ,0},
  { "&Espace r�el occup�",                             StrMSpacefl, French ,0},
  { "B&oules et B�tons",                               StrMBallStk, French ,1},
  { "&Ribbons",                                        StrMRibbons, French ,0},
  { "&Tresses",                                        StrMStrands, French ,0},
  { "Ebauc&hes",                                       StrMCartoon, French ,5},
  { "Surface &Mol�cular",                              StrMMolSurf, French ,8},
  { "&Monochrome",                                     StrMMonochr, French ,0},
  { "&CPK",                                            StrMCPK,     French ,0},
  { "&Forme",                                          StrMShapely, French ,0},
  { "&Groupe",                                         StrMGroup,   French ,0},
  { "C&ha�ne",                                         StrMChain,   French ,1},
  { "&Temp�rature",                                    StrMTemp,    French ,0},
  { "&Structure",                                      StrMStruct,  French ,0},
  { "&Utilisateur",                                    StrMUser,    French ,0},
  { "Mo&d�le",                                         StrMModel,   French ,2},
  { "&Alt",                                            StrMAlt,     French ,0},
  { "Vision en &Coupe",                                StrMSlab,    French ,10},
  { "H&ydrog�nes",                                     StrMHydr,    French ,1},
  { "&H�t�roatomes",                                   StrMHet,     French ,0},
  { "&Reflets",                                        StrMSpec,    French ,0},
  { "&Ombres",                                         StrMShad,    French ,0},
  { "&St�r�o",                                         StrMStereo,  French ,0},
  { "&Labels",                                         StrMLabel,   French ,0},
  { "&D�sactiver Choix",                               StrMPOff,    French ,0},
  { "Activer &Identification",                         StrMPIdent,  French ,8},
  { "Activer &Distance",                               StrMPDist,   French ,8},
  { "Activer &Moniteur",                               StrMPMon,    French ,8},
  { "Activer &Angle",                                  StrMPAng,    French ,8},
  { "Activer &Torsion",                                StrMPTrsn,   French ,8},
  { "Activer &Label",                                  StrMPLabl,   French ,8}, 
  { "Activer &Centre",                                 StrMPCent,   French ,8},
  { "Activer &Coord",                                  StrMPCoord,  French ,8},
  { "Activer L&iaison",                                StrMPBond,   French ,9},
  { "Tourner Li&aison",                                StrMRBond,   French ,10},
  { "Tourner M&ol�cule",                               StrMRMol,    French ,9},
  { "Tourner &Globalement",                            StrMRAll,    French ,8},
  { "&BMP ...",                                        StrMBMP,     French ,0},  
  { "&GIF ...",                                        StrMGIF,     French ,0},  
  { "IRIS &RGB ...",                                   StrMIRGB,    French ,5},  
  { "PP&M ...",                                        StrMPPM,     French ,2},  
  { "&Sun Raster...",                                  StrMSRast,   French ,0},  
  { "&PostScript...",                                  StrMPostscr, French ,0},  
  { "P&ICT...",                                        StrMPICT,    French ,1},  
  { "&Vector PS ...",                                  StrMVECPS,   French ,0},  
  { "M&olscript ...",                                  StrMMSCR,    French ,1},  
  { "&Kinemage ...",                                   StrMKine,    French ,0},  
  { "PO&VRay 3 ...",                                   StrMPOVRAY,  French ,2},  
  { "VRM&L ...",                                       StrMVRML,    French ,3},  
  { "Ram&achandran ...",                               StrMRPP,     French ,3},  
  { "Raster&3D ...",                                   StrMR3D,     French ,6},  
  { "RasMol S&cript ...",                              StrMSCR,     French ,8},  
  { "&A propos de RasMol...",                          StrMAbout,   French ,0},
  { "&Manual utilisateur...",                          StrMUserM,   French ,0},
  { "&Annuler",                                        StrMUndo,    French ,0},
  { "&Couper",                                         StrMCut,     French ,0},
  { "C&opier",                                         StrMCopy,    French ,1},
  { "Co&ller",                                         StrMPaste,   French ,2},
  { "&D�truire",                                       StrMDelete,  French ,0},
  { "&S�lectionner tout",                              StrMSelAll,  French ,0},
  { "&Fichier",                                        StrMFile,    French ,0},
  { "&Editer",                                         StrMEdit,    French ,0},
  { "&Montrer",                                        StrMDisplay, French ,0},
  { "&Couleurs",                                       StrMColour,  French ,0},
  { "&Options",                                        StrMOpt,     French ,0},
  { "Con&figuration",                                  StrMSettings,French ,3},
  { "E&xporter",                                       StrMExport,  French ,1},
  { "&Aide",                                           StrMHelp,    French ,0},
#endif
  { "Nom du fichier PDB:",                             StrPrmtPDB,  French ,0},
  { "Nom du fichier Image:",                           StrPrmtImg,  French ,0},
  { "Nom du fichier de Mol�cule:",                     StrPrmtMol,  French ,0},
  { "Avertissement: ",                                 StrWarn,     French ,0},
  { "Cha�ne",                                          StrChain,    French ,0},
  { "S'enregistrer",                                   StrRegister, French, 0}, 
  { "Donner",                                          StrDonate,   French, 0},
  { "Ne montrez pas ce dialogue au d�marrage",         StrNoShow,   French, 0}, 
  { "Aucunes garantie, Open Source, GPL, donations appr�ci�es", StrWarranty, French, 0},
