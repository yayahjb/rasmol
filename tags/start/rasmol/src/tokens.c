
/***************************************************************************
 *                               RasMol 2.7.3                              *
 *                                                                         *
 *                                 RasMol                                  *
 *                 Molecular Graphics Visualisation Tool                   *
 *                             6 February 2005                             *
 *                                                                         *
 *                   Based on RasMol 2.6 by Roger Sayle                    *
 * Biomolecular Structures Group, Glaxo Wellcome Research & Development,   *
 *                      Stevenage, Hertfordshire, UK                       *
 *         Version 2.6, August 1995, Version 2.6.4, December 1998          *
 *                   Copyright (C) Roger Sayle 1992-1999                   *
 *                                                                         *
 *                          and Based on Mods by                           *
 *Author             Version, Date             Copyright                   *
 *Arne Mueller       RasMol 2.6x1   May 98     (C) Arne Mueller 1998       *
 *Gary Grossman and  RasMol 2.5-ucb Nov 95     (C) UC Regents/ModularCHEM  *
 *Marco Molinaro     RasMol 2.6-ucb Nov 96         Consortium 1995, 1996   *
 *                                                                         *
 *Philippe Valadon   RasTop 1.3     Aug 00     (C) Philippe Valadon 2000   *
 *                                                                         *
 *Herbert J.         RasMol 2.7.0   Mar 99     (C) Herbert J. Bernstein    * 
 *Bernstein          RasMol 2.7.1   Jun 99         1998-2001               *
 *                   RasMol 2.7.1.1 Jan 01                                 *
 *                   RasMol 2.7.2   Aug 00                                 *
 *                   RasMol 2.7.2.1 Apr 01                                 *
 *                   RasMol 2.7.2.1.1 Jan 04                               *
 *                   RasMol 2.7.3   Feb 05                                 *
 *                                                                         *
 *with RasMol 2.7.3 incorporating changes by Clarice Chigbo, Ricky Chachra,*
 *and Mamoru Yamanishi.  Work on RasMol 2.7.3 supported in part by         *
 *grants DBI-0203064, DBI-0315281 and EF-0312612 from the U.S. National    *
 *Science Foundation and grant DE-FG02-03ER63601 from the U.S. Department  *
 *of Energy.                                                               *
 *                                                                         *
 *                    and Incorporating Translations by                    *
 *  Author                               Item                      Language*
 *  Isabel Servan Martinez,                                                *
 *  Jose Miguel Fernandez Fernandez      2.6   Manual              Spanish *
 *  Jose Miguel Fernandez Fernandez      2.7.1 Manual              Spanish *
 *  Fernando Gabriel Ranea               2.7.1 menus and messages  Spanish *
 *  Jean-Pierre Demailly                 2.7.1 menus and messages  French  *
 *  Giuseppe Martini, Giovanni Paolella, 2.7.1 menus and messages          *
 *  A. Davassi, M. Masullo, C. Liotto    2.7.1 help file           Italian *
 *                                                                         *
 *                             This Release by                             *
 * Herbert J. Bernstein, Bernstein + Sons, P.O. Box 177, Bellport, NY, USA *
 *                       yaya@bernstein-plus-sons.com                      *
 *               Copyright(C) Herbert J. Bernstein 1998-2005               *
 *                                                                         *
 *                READ THE FILE NOTICE FOR RASMOL LICENSES                 *
 *Please read the file NOTICE for important notices which apply to this    *
 *package and for license terms (GPL or RASLIC).                           *
 ***************************************************************************/
/* tokens.c
 $Log: not supported by cvs2svn $
 Revision 1.2  2004/09/29 22:39:14  chigboc
 *** empty log message ***

 Revision 1.1  2004/05/07 19:46:16  yaya
 Initial revision

 Revision 1.2  2004/02/15 00:24:00  yaya
 *** empty log message ***

 Revision 1.1  2003/12/12 21:10:38  yaya
 Initial revision

 Revision 1.2  2001/02/06 21:58:18  yaya
 *** empty log message ***

 Revision 1.1  2001/01/31 02:13:45  yaya
 Initial revision

 Revision 1.4  2000/08/26 18:12:46  yaya
 Updates to header comments in all files

 Revision 1.3  2000/08/21 21:07:50  yaya
 semi-final ucb mods

 Revision 1.2  2000/08/09 01:18:18  yaya
 Rough cut with ucb

 */
#include <string.h>
#include <ctype.h>

#include "tokens.h"

int LookUpKeyword( char *ptr )
{
    switch(*ptr++) {
      /*
        ACIDIC               AcidTok
        ACYCLIC              AcyclicTok 
        ALCHEMY              AlchemyTok
        ALIPHATIC            AliphaticTok
        ALL                  AllTok 
        ALPHA                AlphaTok
        ALT                  AltlTok
        AMBIENT              AmbientTok
        AMINO                AminoTok
        AND                  AndTok
        ANGLE                AngleTok
        ANGLES               AngleTok
        AROMATIC             AromaticTok
        ASSE                 AxesTok
        ASSI                 AxesTok
        AT                   ATTok
        ATOM                 AtomTok
        ATOMNO               AtomNoTok
        ATOMNUMBER           AtomNoTok
        ATOMS                AtomTok
        AXES                 AxesTok
        AXIS                 AxesTok
      */
        case('A'):
            switch(*ptr++) {
                case('C'):
                    if( !strcmp(ptr,"IDIC") ) {
                        return( AcidicTok );
                    } else if( !strcmp(ptr,"YCLIC") ) {
                        return( AcyclicTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"CHEMY") ) {
                        return( AlchemyTok );
                    } else if( !strcmp(ptr,"IPHATIC") ) {
                        return( AliphaticTok );
                    } else if( (*ptr=='L') && !ptr[1] ) {
                        return( AllTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( AltlTok );
                    } else if( !strcmp(ptr,"PHA") ) {
                        return( AlphaTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"BIENT") ) {
                        return( AmbientTok );
                    } else if( !strcmp(ptr,"INO") ) {
                        return( AminoTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='D') && !ptr[1] ) {
                        return( AndTok );
                    } else if( !strcmp(ptr,"GLE") ) {
                        return( AngleTok );
                    } else if( !strcmp(ptr,"GLES") ) {
                        return( AngleTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"OMATIC") ) {
                        return( AromaticTok );
                    }
                    break;

                 case('S'):
                    if( !strcmp(ptr,"SE") || !strcmp(ptr,"SI")) {
                        return( AxesTok );
                    }
                    break;

               case('T'):
                    if( !*ptr ) {
                        return( ATTok );
                    } else if( !strcmp(ptr,"OM") ) {
                        return( AtomTok );
                    } else if( !strcmp(ptr,"OMNO") ) {
                        return( AtomNoTok );
                    } else if( !strcmp(ptr,"OMNUMBER") ) {
                        return( AtomNoTok );
                    } else if( !strcmp(ptr,"OMS") ) {
                        return( AtomTok );
                    }
                    break;

                case('X'):
                    if( !strcmp(ptr,"ES") ) {
                        return( AxesTok );
                    } else if( !strcmp(ptr,"IS") ) {
                        return( AxesTok );
                    }
                    break;

            }
            break;

      /*
        BACKBONE             BackboneTok
        BACKFADE             BackFadeTok
        BACKGROUND           BackgroundTok
        BASIC                BasicTok
        BIOSYM               BiosymTok
        BLACK                BlackTok
        BLUE                 BlueTok
        BLUETINT             BlueTintTok
        BMP                  BMPTok
        BOND                 BondTok
        BONDED               BondedTok
        BONDMODE             BondModeTok
        BONDS                BondTok
        BOUNDBOX             BoundBoxTok
        BOUNDINGBOX          BoundBoxTok
        BROWN                BrownTok
        BURIED               BuriedTok
      */

        case('B'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"CKBONE") ) {
                        return( BackboneTok );
                    } else if( !strcmp(ptr,"CKFADE") ) {
                        return( BackFadeTok );
                    } else if( !strcmp(ptr,"CKGROUND") ) {
                        return( BackgroundTok );
                    } else if( !strcmp(ptr,"SIC") ) {
                        return( BasicTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"OSYM") ) {
                        return( BiosymTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"ACK") ) {
                        return( BlackTok );
                    } else if( !strcmp(ptr,"UE") ) {
                        return( BlueTok );
                    } else if( !strcmp(ptr,"UETINT") ) {
                        return( BlueTintTok );
                    }
                    break;

                case('M'):
                    if( (*ptr=='P') && !ptr[1] ) {
                        return( BMPTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"ND") ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"NDED") ) {
                        return( BondedTok );
                    } else if( !strcmp(ptr,"NDMODE") ) {
                        return( BondModeTok );
                    } else if( !strcmp(ptr,"NDS") ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"UNDBOX") ) {
                        return( BoundBoxTok );
                    } else if( !strcmp(ptr,"UNDINGBOX") ) {
                        return( BoundBoxTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"OWN") ) {
                        return( BrownTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RIED") ) {
                        return( BuriedTok );
                    }
                    break;

            }
            break;

      /*
        CADENA               ChainTok
        CADENAS              ChainTok
        CARTOON              CartoonTok
        CARTOONS             CartoonTok
        CATENA               ChainTok
        CATENE               ChainTok
        CENTER               CentreTok
        CENTRE               CentreTok
        CEX                  CEXTok
        CG                   CGTok
        CHAIN                ChainTok
        CHAINS               ChainTok
        CHARGE               ChargeTok
        CHARGED              ChargedTok
        CHARGES              ChargeTok
        CHARMM               CharmmTok
        CIF                  CIFTok
        CISANGLE             CisAngleTok
        CISBONDED            CisBondedTok
        CLIPBOARD            ClipboardTok
        COLOR                ColourTok
        COLORS               ColourTok
        COLOUR               ColourTok
        COLOURS              ColourTok
        CONNECT              ConnectTok
        COORDINATE           CoordTok
        COORDINATES          CoordTok
        COORD                CoordTok
        COORDS               CoordTok
        COPY                 CopyTok
        CPK                  CPKTok
	CPKNEW               CpkNewTok
        CYAN                 CyanTok
        CYCLIC               CyclicTok
        CYSTINE              CystineTok
      */

        case('C'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"DENA") || !strcmp(ptr,"DENAS")) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"RTOON") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"RTOONS") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"TENA") || !strcmp(ptr,"TENE")) {
                        return( ChainTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"NTER") ) {
                        return( CentreTok );
                    } else if( !strcmp(ptr,"NTRE") ) {
                        return( CentreTok );
                    } else if( (*ptr=='X') && !ptr[1] ) {
                        return( CEXTok );
                    }
                    break;

                case('G'):
                    if( !*ptr ) {
                        return( CGTok );
                    }
                    break;

                case('H'):
                    if( !strcmp(ptr,"AIN") ) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"AINS") ) {
                        return( ChainTok );
                    } else if( !strcmp(ptr,"ARGE") ) {
                        return( ChargeTok );
                    } else if( !strcmp(ptr,"ARGED") ) {
                        return( ChargedTok );
                    } else if( !strcmp(ptr,"ARGES") ) {
                        return( ChargeTok );
                    } else if( !strcmp(ptr,"ARMM") ) {
                        return( CharmmTok );
                    }
                    break;

                case('I'):
                    if( (*ptr=='F') && !ptr[1] ) {
                        return( CIFTok );
                    } else if ( !strcmp(ptr,"SANGLE") ) {
                        return( CisAngleTok );
                    } else if ( !strcmp(ptr,"SBONDED") ) {
                        return( CisBondedTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"IPBOARD") ) {
                        return( ClipboardTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LOR") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"LORS") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"LOUR") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"LOURS") ) {
                        return( ColourTok );
                    } else if( !strcmp(ptr,"NNECT") ) {
                        return( ConnectTok );
                    } else if( !strcmp(ptr,"ORDINATE") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORDINATES") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORD") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"ORDS") ) {
                        return( CoordTok );
                    } else if( !strcmp(ptr,"PY") ) {
                        return( CopyTok );
                    }
                    break;

                case('P'):
                    if( (*ptr=='K') && !ptr[1] ) {
                        return( CPKTok );
                    } else if( !strcmp(ptr,"KNEW") ) {
                      return( CpkNewTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"AN") ) {
                        return( CyanTok );
                    } else if( !strcmp(ptr,"CLIC") ) {
                        return( CyclicTok );
                    } else if( !strcmp(ptr,"STINE") ) {
                        return( CystineTok );
                    }
                    break;

            }
            break;


      /*
        DASH                 DashTok
        DASHES               DashTok
        DATA_...             CIFDataTok
        DEFINE               DefineTok
		DEPTH                DepthTok
        DEPTHCUE             DepthCueTok
        DIBUJO               CartoonTok
        DIBUJOS              CartoonTok
        DISPLAY              DisplayTok
        DISTANCE             DistanceTok
        DISTANCES            DistanceTok
        DNA                  DNATok
        DOTS                 DotsTok
      */

        case('D'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"SH") ) {
                        return( DashTok );
                    } else if( !strcmp(ptr,"SHES") ) {
                        return( DashTok );
                    } else if( !strncmp(ptr, "TA_", 3) ) {
                        return( CIFDataTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"FINE") ) {
                        return( DefineTok );
                    } else if( !strcmp(ptr,"PTH") ) {
                        return( DepthTok );
                    } else if( !strcmp(ptr,"PTHCUE") ) {
                        return( DepthCueTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"BUJO") || !strcmp(ptr,"BUJOS") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"SPLAY") ) {
                        return( DisplayTok );
                    } else if( !strcmp(ptr,"STANCE") ) {
                        return( DistanceTok );
                    } else if( !strcmp(ptr,"STANCES") ) {
                        return( DistanceTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='A') && !ptr[1] ) {
                        return( DNATok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"TS") ) {
                        return( DotsTok );
                    }
                    break;

            }
            break;

      /*
        E                    AndTok
        ECHO                 EchoTok
        EJE                  AxesTok
        EJES                 AxesTok
        ELANCE               BondTok
        ELANCES              BondTok
        ELEMNO               ElemNoTok
        ELEMENTNUMBER        ElemNoTok
        ELICHE               HelixTok
        ENGLISH              EnglishTok
        EPSF                 EPSFTok
        ELICHE               HelixTok
        ESQUELETO            BackboneTok
        ETIQUETA             LabelTok
        ETIQUETAS            LabelTok
        ETICHETTA            LabelTok
        ETICHETTE            LabelTok  
        EXIT                 ExitTok
      */

        case('E'):
            switch(*ptr++) {
                case('\0'):
                    return( AndTok );
                    break;

                case('C'):
                    if( !strcmp(ptr,"HO") ) {
                        return( EchoTok );
                    }
                    break;

                case('J'):
                    if( *ptr=='E' && (!ptr[1] || ptr[1]=='S')) {
                        return( AxesTok );
                    }
                    break;
 
                case('L'):
                    if( !strcmp(ptr,"ANCE") || !strcmp(ptr,"ANCES" ) ) {
                        return( BondTok );
                    } else if( !strcmp(ptr,"EMNO") ) {
                        return( ElemNoTok );
                    } else if( !strcmp(ptr,"EMENTNUMBER") ) {
                        return( ElemNoTok );
                     } else if( !strcmp(ptr,"ICHE") ) {
                        return( HelixTok );
                   }
                    break;

                case('N'):
                    if( !strcmp(ptr,"GLISH") ) {
                        return( EnglishTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"SF") ) {
                        return( EPSFTok );
                    }
                    break;

                case('S'):
                    if( !strcmp(ptr,"QUELETO") ) {
                        return( BackboneTok );
                    } else if( !strcmp(ptr,"CI") ) {
                        return( ExitTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"IQUETA") || !strcmp(ptr,"IQUETAS") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"ICHETTA") || !strcmp(ptr,"ICHETTE") ) {
                        return( LabelTok );
                    }
                    break;

                case('X'):
                    if( !strcmp(ptr,"IT") ) {
                        return( ExitTok );
                    }
                    break;

            }
            break;

      /*
        FALSE                FalseTok
        FDAT                 FDATTok
        FILODIFERRO          WireframeTok
        FILDIFERRO           WireframeTok
        FILI                 StrandsTok  
        FONTSIZE             FontSizeTok
        FONTSTROKE           FontStrokeTok
        FRENCH               FrenchTok
        FS                   FSTok
      */

        case('F'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LSE") ) {
                        return( FalseTok );
                    }
                    break;

                case('D'):
                    if( !strcmp(ptr,"AT") ) {
                        return( FDATTok );
                    }
                    break;

                case('I'):
                	if( !strcmp(ptr,"LODIFERRO") || !strcmp(ptr,"LDIFERRO")) {
                        return( WireframeTok );
                    } else if( !strcmp(ptr,"LI") ) {
                        return( StrandsTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"NTSIZE") ) {
                        return( FontSizeTok );
                    } else if( !strcmp(ptr,"NTSTROKE") ) {
                        return( FontStrokeTok );
                    }
                    break;
                
                case('R'):
                    if( !strcmp(ptr,"ENCH") ) {
                        return( FrenchTok );
                    }
                    break;

                case('S'):
                    if( !ptr[0] ) {
                        return( FSTok );
                    }
                    break;

            }
            break;

      /*
        GAUSSIAN             GaussianTok
        GIF                  GIFTok
        GIRO                 TurnTok
        GIROS                TurnTok
        GOLD                 GoldTok
        GRAY                 GrayTok
        GREEN                GreenTok
        GREENBLUE            GreenBlueTok
        GREENTINT            GreenTintTok
        GREY                 GrayTok
        GROUP                GroupTok
        GRUPO                GroupTok
        GRUPPO               GroupTok 
      */

        case('G'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"USSIAN") ) {
                        return( GaussianTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"RO") || !strcmp(ptr,"ROS") ) {
                        return( TurnTok );
                    } else if( (*ptr=='F') && !ptr[1] ) {
                        return( GIFTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LD") ) {
                        return( GoldTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"AY") ) {
                        return( GrayTok );
                    } else if( !strcmp(ptr,"EEN") ) {
                        return( GreenTok );
                    } else if( !strcmp(ptr,"EENBLUE") ) {
                        return( GreenBlueTok );
                    } else if( !strcmp(ptr,"EENTINT") ) {
                        return( GreenTintTok );
                    } else if( !strcmp(ptr,"EY") ) {
                        return( GrayTok );
                    } else if( !strcmp(ptr,"OUP") || !strcmp(ptr,"UPO") ) {
                        return( GroupTok );
                     } else if( !strcmp(ptr,"UPPO") ) {
                        return( GroupTok );
                   }
                    break;

            }
            break;

      /*
        HALF                 HalfTok
        HARDWARE             HardwareTok
        HBOND                HBondTok
        HBONDS               HBondTok
        HEADER               HeaderTok
        HEBRAS               StrandsTok
        HELICES              HelixTok
        HELIX                HelixTok
        HELP                 HelpTok
        HETERO               HeteroTok
        HOLLOW               HollowTok
        HOTPINK              HotPinkTok
        HOURGLASS            HourGlassTok
        HYDROGEN             HydrogenTok
        HYDROPHOBIC          HydrophobicTok
      */

        case('H'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LF") ) {
                        return( HalfTok );
                    } else if( !strcmp(ptr,"RDWARE") ) {
                        return( HardwareTok );
                    }
                    break;

                case('B'):
                    if( !strcmp(ptr,"OND") ) {
                        return( HBondTok );
                    } else if( !strcmp(ptr,"ONDS") ) {
                        return( HBondTok );
                    }
                    break;

                case('E'):
	  	    if( !strcmp(ptr,"ADER") ) {
                        return( HeaderTok );
                    } else if( !strcmp(ptr,"BRAS") ) {
                        return( StrandsTok );
                    } else if( !strcmp(ptr,"LICES") ) {
                        return( HelixTok );
                    } else if( !strcmp(ptr,"LIX") ) {
                        return( HelixTok );
                    } else if( !strcmp(ptr,"LP") ) {
                        return( HelpTok );
                    } else if( !strcmp(ptr,"TERO") ) {
                        return( HeteroTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LLOW") ) {
                        return( HollowTok );
                    } else if( !strcmp(ptr,"TPINK") ) {
                        return( HotPinkTok );
                    } else if( !strcmp(ptr,"URGLASS") ) {
                        return( HourGlassTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"DROGEN") ) {
                        return( HydrogenTok );
                    } else if( !strcmp(ptr,"DROPHOBIC") ) {
                        return( HydrophobicTok );
                    }
                    break;

            }
            break;

      /*
        IDENT                IdentifyTok
        IDENTIFY             IdentifyTok
		IMAGE				 ImageTok
        INFO                 InfoTok
        INFORMATION          InfoTok
        INLINE               InLineTok
        INSIGHT              InsightTok
        ION                  IonTok
        IONS                 IonTok
        IRIS                 IRISTok
        ITALIAN              ItalianTok
      */

        case('I'):
            switch(*ptr++) {
                case('D'):
                    if( !strcmp(ptr,"ENT") ) {
                        return( IdentifyTok );
                    } else if( !strcmp(ptr,"ENTIFY") ) {
                        return( IdentifyTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"AGE") )
                        return( ImageTok );
					break;

                case('N'):
                    if( !strcmp(ptr,"FO") ) {
                        return( InfoTok );
                    } else if( !strcmp(ptr,"FORMATION") ) {
                        return( InfoTok );
                    } else if( !strcmp(ptr,"LINE") ) {
                        return( InLineTok );
                    } else if( !strcmp(ptr,"SIGHT") ) {
                        return( InsightTok );
                    }
                    break;

                case('O'):
                    if( (*ptr=='N') && !ptr[1] ) {
                        return( IonTok );
                    } else if( !strcmp(ptr,"NS") ) {
                        return( IonTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"IS") ) {
                        return( IRISTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"ALIAN") ) {
                        return( ItalianTok );
                    }
                    break;

            }
            break;

      /*
        JPEG                 JPEGTok
      */

        case('J'):
            if( !strcmp(ptr,"PEG") ) {
                return( JPEGTok );
            }
            break;

      /*
        KINEMAGE             KinemageTok
      */

        case('K'):
            if( !strcmp(ptr,"INEMAGE") ) {
                return( KinemageTok );
            }
            break;

      /*
        LABEL                LabelTok
        LABELS               LabelTok
        LARGE                LargeTok
        LIGAND               LigandTok
        LIGANDS              LigandTok
        LOAD                 LoadTok
      */

        case('L'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"BEL") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"BELS") ) {
                        return( LabelTok );
                    } else if( !strcmp(ptr,"RGE") ) {
                        return( LargeTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"GAND") ) {
                        return( LigandTok );
                    } else if( !strcmp(ptr,"GANDS") ) {
                        return( LigandTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"AD") ) {
                        return( LoadTok );
                    }
                    break;

            }
            break;

      /*
        MACROMODEL           MacroModelTok
        MAGENTA              MagentaTok
        MAINCHAIN            MainChainTok
        MDL                  MDLTok
        MEDIUM               MediumTok
        MENUS                MenusTok
        MMDB                 MMDBTok
        MODEL                ModelTok
        MOL2                 Mol2Tok
        MOLECULE             MoleculeTok
        MOLSCRIPT            MolScriptTok
        MOLSURF		     MolSurfTok
        MONITOR              MonitorTok
        MONITORS             MonitorTok
        MONO                 MonoTok
        MONOCHROME           MonoTok
        MONOPS               MonoPSTok
        MOPAC                MOPACTok
        MOSTRAR              DisplayTok
        MOUSE                MouseTok
        MOUSEMODE            MouseTok
      */

        case('M'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"CROMODEL") ) {
                        return( MacroModelTok );
                    } else if( !strcmp(ptr,"GENTA") ) {
                        return( MagentaTok );
                    } else if( !strcmp(ptr,"INCHAIN") ) {
                        return( MainChainTok );
                    }
                    break;

                case('D'):
                    if( (*ptr=='L') && !ptr[1] ) {
                        return( MDLTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"DIUM") ) {
                        return( MediumTok );
                    } else if( !strcmp(ptr,"NUS") ) {
                        return( MenusTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"DB") ) {
                        return( MMDBTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"DEL") ) {
                        return( ModelTok );
                    } else if( !strcmp(ptr,"L2") ) {
                        return( Mol2Tok );
                    } else if( !strcmp(ptr,"LECULE") ) {
		                return( MoleculeTok );
                    } else if( !strcmp(ptr,"LSCRIPT") ) {
                        return( MolScriptTok );
                    } else if( !strcmp(ptr,"LSURF") ) {
                        return( MolSurfTok );
                    } else if( !strcmp(ptr,"NITOR") ) {
                        return( MonitorTok );
                    } else if( !strcmp(ptr,"NITORS") ) {
                        return( MonitorTok );
                    } else if( !strcmp(ptr,"NO") ) {
                        return( MonoTok );
                    } else if( !strcmp(ptr,"NOCHROME") ) {
                        return( MonoTok );
                    } else if( !strcmp(ptr,"NOPS") ) {
                        return( MonoPSTok );
                    } else if( !strcmp(ptr,"PAC") ) {
                        return( MOPACTok );
                    } else if( !strcmp(ptr,"STRAR") ) {
                        return( DisplayTok );
                    } else if( !strcmp(ptr,"USE") ) {
                        return( MouseTok );
                    } else if( !strcmp(ptr,"USEMODE") ) {
                        return( MouseTok );
                    }
                    break;

            }
            break;

      /*
        NASTRO               RibbonTok 
        NASTRI               RibbonTok 
        NEGATIVE             AcidicTok
        NEUTRAL              NeutralTok
        NMRPDB               NMRPDBTok
        NONE                 NoneTok
        NORMAL               NormalTok
        NOT                  NotTok
        NUCLEIC              NucleicTok
      */

         case('N'):
            switch(*ptr++) {
                case('A'):
                	if( !strcmp(ptr,"STRO") || !strcmp(ptr,"STRI") ) {
                        return( RibbonTok );
                    }
                    break;
            
                case('E'):
                    if( !strcmp(ptr,"GATIVE") ) {
                        return( AcidicTok );
                    } else if( !strcmp(ptr,"UTRAL") ) {
                        return( NeutralTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"RPDB") ) {
                        return( NMRPDBTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"NE") ) {
                        return( NoneTok );
                    } else if( !strcmp(ptr,"RMAL") ) {
                        return( NormalTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( NotTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"CLEIC") ) {
                        return( NucleicTok );
                    }
                    break;

            }
            break;

      /*
        OFF                  FalseTok
        ON                   TrueTok
        OR                   OrTok
        ORANGE               OrangeTok
        ORIGIN               OriginTok
      */
        case('O'):
            switch(*ptr++) {
                case('F'):
                    if( (*ptr=='F') && !ptr[1] ) {
                        return( FalseTok );
                    }
                    break;

                case('N'):
                    if( !*ptr ) {
                        return( TrueTok );
                    }
                    break;

                case('R'):
                    if( !*ptr ) {
                        return( OrTok );
                    } else if( !strcmp(ptr,"ANGE") ) {
                        return( OrangeTok );
                    } else if( !strcmp(ptr,"IGIN") ) {
                        return( OriginTok );
                    }
                    break;

            }
            break;

      /*
        PASTE				 PasteTok
        PAUSE                WaitTok
        PDB                  PDBTok
        PHIPSI               PhiPsiTok
        PICK                 PickingTok
        PICKING              PickingTok
        PICT                 PICTTok
        PINK                 PinkTok
        PINKTINT             PinkTintTok
        PNG                  PNGTok
        POLAR                PolarTok
        POSITIVE             BasicTok
		POSITION			 PositionTok
        POTENTIAL            PotentialTok
        POVRAY               POVRayTok
        POVRAY2              POVRay2Tok
        POVRAY3              POVRay3Tok
        PPM                  PPMTok
        PRINT                PrintTok
        PROTEIN              ProteinTok
        PS                   EPSFTok
        PURINE               PurineTok
        PURINES              PurineTok
        PURPLE               PurpleTok
        PYRIMIDINE           PyrimidineTok
        PYRIMIDINES          PyrimidineTok
      */

        case('P'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"STE") ) {
                        return( PasteTok );
                    } else if( !strcmp(ptr,"USE") ) {
                        return( WaitTok );
                    }
                    break;

                case('D'):
                    if( (*ptr=='B') && !ptr[1] ) {
                        return( PDBTok );
                    }
                    break;

	        case('H'):
                    if( !strcmp(ptr,"IPSI") ) {
                        return( PhiPsiTok );
                    } 

                case('I'):
                    if( !strcmp(ptr,"CK") ) {
                        return( PickingTok );
                    } else if( !strcmp(ptr,"CKING") ) {
                        return( PickingTok );
                    } else if( !strcmp(ptr,"CT") ) {
                        return( PICTTok );
                    } else if( !strcmp(ptr,"NK") ) {
                        return( PinkTok );
                    } else if( !strcmp(ptr,"NKTINT") ) {
                        return( PinkTintTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='G') && !ptr[1] ) {
                        return( PNGTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LAR") ) {
                        return( PolarTok );
                    } else if( !strcmp(ptr,"SITIVE") ) {
                        return( BasicTok );
                    } else if( !strcmp(ptr,"SITION") ) {
                        return( PositionTok );
                    } else if( !strcmp(ptr,"TENTIAL") ) {
                        return( PotentialTok );
                    } else if( !strcmp(ptr,"VRAY") ) {
                        return( POVRayTok );
                    } else if( !strcmp(ptr,"VRAY2") ) {
                        return( POVRay2Tok );
                    } else if( !strcmp(ptr,"VRAY3") ) {
                        return( POVRay3Tok );
                    }
                    break;

                case('P'):
                    if( (*ptr=='M') && !ptr[1] ) {
                        return( PPMTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"INT") ) {
                        return( PrintTok );
                    } else if( !strcmp(ptr,"OTEIN") ) {
                        return( ProteinTok );
                    }
                    break;

                case('S'):
                    if( !*ptr ) {
                        return( EPSFTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RINE") ) {
                        return( PurineTok );
                    } else if( !strcmp(ptr,"RINES") ) {
                        return( PurineTok );
                    } else if( !strcmp(ptr,"RPLE") ) {
                        return( PurpleTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"RIMIDINE") ) {
                        return( PyrimidineTok );
                    } else if( !strcmp(ptr,"RIMIDINES") ) {
                        return( PyrimidineTok );
                    }
                    break;

            }
            break;

      /*
        QUANTA               QuantaTok
        QUIT                 QuitTok
      */

        case('Q'):
            if( *ptr++ == 'U' ) {
                if( !strcmp(ptr,"ANTA") ) {
                    return( QuantaTok );
                } else if( !strcmp(ptr,"IT") ) {
                    return( QuitTok );
                }
            }
            break;

      /*
        RADIUS               RadiusTok
        RAMACHAN             RamachanTok
        RAMACHANDRANDATAFILE RamachanTok
        RAMACHANDRANPRINTERPLOT RamPrintTok
        RAMDATA              RamachanTok
        RAMPRINT             RamPrintTok
        RASMAC               RasMolTok
        RASMOL               RasMolTok
        RASWIN               RasMolTok
        RDF                  RamachanTok
        RED                  RedTok
        REDORANGE            RedOrangeTok
        REFRESH              RefreshTok
        REJECT               RejectTok
        RENUM                RenumTok
        RENUMBER             RenumTok
        RESET                ResetTok
        RESIDUE              ResidueTok
        RESIDUENUMBER        ResNoTok
        RESIZE               ResizeTok
        RESNO                ResNoTok
        RESTRICT             RestrictTok
        RGB                  IRISTok
        RIBBON               RibbonTok
        RIBBON1              Ribbon1Tok
        RIBBON2              Ribbon2Tok
        RIBBONS              RibbonTok
        RIBBONS1             Ribbon1Tok
        RIBBONS2             Ribbon2Tok
        RIEMPIMENTO          SpacefillTok
        RNA                  RNATok
        ROT                  RotateTok
        ROTATE               RotateTok
        ROTATION             RotateTok
        RPP                  RamPrintTok
      */

        case('R'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"DIUS") ) {
                        return( RadiusTok );
                    } else if( !strcmp(ptr,"MACHAN") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MACHANDRANDATAFILE") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MACHANDRANPRINTERPLOT") ) {
                        return( RamPrintTok );
                    } else if( !strcmp(ptr,"MDATA") ) {
                        return( RamachanTok );
                    } else if( !strcmp(ptr,"MPRINT") ) {
                        return( RamPrintTok );
                    } else if( !strcmp(ptr,"SMAC") ) {
                        return( RasMolTok );
                    } else if( !strcmp(ptr,"SMOL") ) {
                        return( RasMolTok );
                    } else if( !strcmp(ptr,"SWIN") ) {
                        return( RasMolTok );
                    }
                    break;

                case('D'):
                    if( !strcmp(ptr,"F") ) {
                        return( RamachanTok );
                    }
                    break;

                case('E'):
                    if( (*ptr=='D') && !ptr[1] ) {
                        return( RedTok );
                    } else if( !strcmp(ptr,"DORANGE") ) {
                        return( RedOrangeTok );
                    } else if( !strcmp(ptr,"FRESH") ) {
                        return( RefreshTok );
                    } else if( !strcmp(ptr,"JECT") ) {
                        return( RejectTok );
                    } else if( !strcmp(ptr,"NUM") ) {
                        return( RenumTok );
                    } else if( !strcmp(ptr,"NUMBER") ) {
                        return( RenumTok );
                    } else if( !strcmp(ptr,"SET") ) {
                        return( ResetTok );
                    } else if( !strcmp(ptr,"SIDUE") ) {
                        return( ResidueTok );
                    } else if( !strcmp(ptr,"SIDUENUMBER") ) {
                        return( ResNoTok );
                    } else if( !strcmp(ptr,"SIZE") ) {
                        return( ResizeTok );
                    } else if( !strcmp(ptr,"SNO") ) {
                        return( ResNoTok );
                    } else if( !strcmp(ptr,"STRICT") ) {
                        return( RestrictTok );
                    }
                    break;

                case('G'):
                    if( (*ptr=='B') && !ptr[1] ) {
                        return( IRISTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"BBON") ) {
                        return( RibbonTok );
                    } else if( !strcmp(ptr,"BBON1") ) {
                        return( Ribbon1Tok );
                    } else if( !strcmp(ptr,"BBON2") ) {
                        return( Ribbon2Tok );
                    } else if( !strcmp(ptr,"BBONS") ) {
                        return( RibbonTok );
                    } else if( !strcmp(ptr,"BBONS1") ) {
                        return( Ribbon1Tok );
                    } else if( !strcmp(ptr,"BBONS2") ) {
                        return( Ribbon2Tok );
                    } else if( !strcmp(ptr,"EMPIMENTO") ) {
                        return( SpacefillTok );
                    }
                    break;

                case('N'):
                    if( (*ptr=='A') && !ptr[1] ) {
                        return( RNATok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"TATE") ) {
                        return( RotateTok );
                    } else if( !strcmp(ptr,"T") ) {
                        return( RotateTok );
                    } else if( !strcmp(ptr,"TATION") ) {
                        return( RotateTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"P") ) {
                        return( RamPrintTok );
                    }
                    break;
            }
            break;

      /*
        SALIR                ExitTok
        SAVE                 SaveTok
        SCHELETRO            BackboneTok
        SCRIPT               ScriptTok
        SECTION              SectionTok
        SEAGREEN             SeaGreenTok
        SELECT               SelectTok
        SELECTED             SelectedTok
        SELECTION            SelectionTok
        SEQUENCE             SequenceTok
        SET                  SetTok
        SHADEPOWER           ShadePowerTok
        SHADOW               ShadowTok
        SHADOWS              ShadowTok
        SHAPELY              ShapelyTok
        SHEET                SheetTok
        SHEETS               SheetTok
        SHELX                SHELXTok
        SHOW                 ShowTok
        SIDECHAIN            SidechainTok
        SKYBLUE              SkyBlueTok
        SLAB                 SlabTok
        SLABMODE             SlabModeTok
        SMALL                SmallTok
        SOLID                SolidTok
        SOLVENT              SolventTok
        SOLVENTS             SolventTok
        SOURCE               SourceTok
        SPACEFILL            SpacefillTok
        SPANISH              SpanishTok
        SPECPOWER            SpecPowerTok
        SPECULAR             SpecularTok
        SSBOND               SSBondTok
        SSBONDS              SSBondTok
        STAR                 StarTok
        STARS                StarTok
        STEREO               StereoTok
        STRANDS              StrandsTok
        STRUCTURE            StructureTok
        SUN                  SUNTok
        SUNRLE               SUNRLETok
        SURFACE              SurfaceTok
        SYBYL                SybylTok
        SYMMETRY             SymmetryTok
      */

        case('S'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"LIR") ) {
                        return( ExitTok );
                    } else if( !strcmp(ptr,"VE") ) {
                        return( SaveTok );
                    }
                    break;

                case('C'):
                    if( !strcmp(ptr,"RIPT") ) {
                        return( ScriptTok );
                    } else if( !strcmp(ptr,"HELETRO") ) {
                        return( BackboneTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"AGREEN") ) {
                        return( SeaGreenTok );
                    } else if( !strcmp(ptr,"CTION") ) {
                        return( SectionTok );
                    } else if( !strcmp(ptr,"LECT") ) {
                        return( SelectTok );
                    } else if( !strcmp(ptr,"LECTED") ) {
                        return( SelectedTok );
                    } else if( !strcmp(ptr,"LECTION") ) {
                        return( SelectedTok );
                     } else if( !strcmp(ptr,"QUENCE") ) {
                        return( SequenceTok );
                    } else if( (*ptr=='T') && !ptr[1] ) {
                        return( SetTok );
                    }
                    break;

                case('H'):
                     if( !strcmp(ptr,"ADEPOWER") ) {
                        return( ShadePowerTok );
                    } else if( !strcmp(ptr,"ADOW") ) {
                       return( ShadowTok );
                    } else if( !strcmp(ptr,"ADOWS") ) {
                        return( ShadowTok );
                    } else if( !strcmp(ptr,"APELY") ) {
                        return( ShapelyTok );
                    } else if( !strcmp(ptr,"EET") ) {
                        return( SheetTok );
                    } else if( !strcmp(ptr,"EETS") ) {
                        return( SheetTok );
                    } else if( !strcmp(ptr,"ELX") ) {
                        return( SHELXTok );
                    } else if( !strcmp(ptr,"OW") ) {
                        return( ShowTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"DECHAIN") ) {
                        return( SidechainTok );
                    }
                    break;

                case('K'):
                    if( !strcmp(ptr,"YBLUE") ) {
                        return( SkyBlueTok );
                    }
                    break;

                case('L'):
                    if( !strcmp(ptr,"AB") ) {
                        return( SlabTok );
                    } else if( !strcmp(ptr,"ABMODE") ) {
                        return( SlabModeTok );
                    }
                    break;

                case('M'):
                    if( !strcmp(ptr,"ALL") ) {
                        return( SmallTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"LID") ) {
                        return( SolidTok );
                    } else if( !strcmp(ptr,"LVENT") ) {
                        return( SolventTok );
                    } else if( !strcmp(ptr,"LVENTS") ) {
                        return( SolventTok );
                    } else if( !strcmp(ptr,"URCE") ) {
                        return( SourceTok );
                    }
                    break;

                case('P'):
                    if( !strcmp(ptr,"ACEFILL") ) {
                        return( SpacefillTok );
                    } else if( !strcmp(ptr,"ANISH") ) {
                        return( SpanishTok );
                    } else if( !strcmp(ptr,"ECPOWER") ) {
                        return( SpecPowerTok );
                    } else if( !strcmp(ptr,"ECULAR") ) {
                        return( SpecularTok );
                    }
                    break;

                case('S'):
                    if( !strcmp(ptr,"BOND") ) {
                        return( SSBondTok );
                    } else if( !strcmp(ptr,"BONDS") ) {
                        return( SSBondTok );
                    }
                    break;

                case('T'):
                    if( !strcmp(ptr,"AR") || !strcmp(ptr,"ARS") ){
                        return( StarTok );
                    } else if( !strcmp(ptr,"EREO") ) {
                        return( StereoTok );
                    } else if( !strcmp(ptr,"RANDS") ) {
                        return( StrandsTok );
                    } else if( !strcmp(ptr,"RUCTURE") ) {
                        return( StructureTok );
                    }
                    break;

                case('U'):
                    if( (*ptr=='N') && !ptr[1] ) {
                        return( SUNTok );
                    } else if( !strcmp(ptr,"NRLE") ) {
                        return( SUNRLETok );
                    } else if( !strcmp(ptr,"RFACE") ) {
                        return( SurfaceTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"BYL") ) {
                        return( SybylTok );
                    } else if( !strcmp(ptr,"MMETRY") ) {
                        return( SymmetryTok );
                    }
                    break;

            }
            break;

      /*
        TEMPERATURE          TemperatureTok
        TITLE                TitleTok
        TODO                 AllTok
        TORSION              TorsionTok
        TORSIONS             TorsionTok
        TRACE                TraceTok
        TRANSLATE            TranslateTok
        TRANSLATION          TranslateTok
        TRANSPARENT          TransparentTok
        TRUE                 TrueTok
        TURN                 TurnTok
        TURNS                TurnTok
        TUTTO                AllTok 
        TYPE                 TypeTok
      */

        case('T'):
            switch(*ptr++) {
                case('E'):
                    if( !strcmp(ptr,"MPERATURE") ) {
                        return( TemperatureTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"TLE") ) {
                        return( TitleTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"DO") ) {
                        return( AllTok );
                    } else if( !strcmp(ptr,"RSION") ) {
                        return( TorsionTok );
                    } else if( !strcmp(ptr,"RSIONS") ) {
                        return( TorsionTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ACE") ) {
                        return( TraceTok );
                    } else if( !strcmp(ptr,"ANSLATE") ) {
                        return( TranslateTok );
                    } else if( !strcmp(ptr,"ANSLATION") ) {
                        return( TranslateTok );
                    } else if( !strcmp(ptr,"ANSPARENT") ) {
                        return( TransparentTok );
                    } else if( !strcmp(ptr,"UE") ) {
                        return( TrueTok );
                    }
                    break;

                case('U'):
                    if( !strcmp(ptr,"RN") ) {
                        return( TurnTok );
                    } else if( !strcmp(ptr,"RNS") ) {
                        return( TurnTok );
                    } else if( !strcmp(ptr,"TTO") ) {
                        return( AllTok );
                    }
                    break;

                case('Y'):
                    if( !strcmp(ptr,"PE") ) {
                        return( TypeTok );
                    }
                    break;

            }
            break;

      /*
        UNBOND               UnBondTok
        UNITCELL             UnitCellTok
        USER                 UserTok
      */

        case('U'):
            switch(*ptr++) {
                case('N'):
                    if( !strcmp(ptr,"ITCELL") ) {
                        return( UnitCellTok );
                    } else if( !strcmp(ptr,"BOND") ) {
                        return( UnBondTok );
                    }
                    break;

                case('S'):
                    if( !strcmp(ptr,"ER") ) {
                        return( UserTok );
                    }
                    break;

            }
            break;

      /*
        VDW                  VDWTok
        VECTPS               VectPSTok
		VIEW                 ViewTok
        VIGNETTA             CartoonTok
        VIOLET               VioletTok
        VISUALIZZA           DisplayTok 
        VRML                 VRMLTok
      */

        case('V'):
            switch(*ptr++) {
                case('D'):
                    if( (*ptr=='W') && !ptr[1] ) {
                        return( VDWTok );
                    }
                    break;

                case('E'):
                    if( !strcmp(ptr,"CTPS") ) {
                        return( VectPSTok );
                    }
                    break;

                case('I'):
                     if( !strcmp(ptr,"EW") ) {
                        return( ViewTok );
                    } else if( !strcmp(ptr,"GNETTA") ) {
                        return( CartoonTok );
                    } else if( !strcmp(ptr,"OLET") ) {
                        return( VioletTok );
                    } else if( !strcmp(ptr,"SUALIZZA") ) {
                        return( DisplayTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ML") ) {
                        return( VRMLTok );
                    }
                    break;

            }
            break;

      /*
        WAIT                 WaitTok
        WATER                WaterTok
        WATERS               WaterTok
        WHITE                WhiteTok
        WIREFRAME            WireframeTok
        WITHIN               WithinTok
        WRITE                WriteTok
      */

        case('W'):
            switch(*ptr++) {
                case('A'):
                    if( !strcmp(ptr,"IT") ) {
                        return( WaitTok );
                    } else if( !strcmp(ptr,"TER") ) {
                        return( WaterTok );
                    } else if( !strcmp(ptr,"TERS") ) {
                        return( WaterTok );
                    }
                    break;

                case('H'):
                    if( !strcmp(ptr,"ITE") ) {
                        return( WhiteTok );
                    }
                    break;

                case('I'):
                    if( !strcmp(ptr,"REFRAME") ) {
                        return( WireframeTok );
                    } else if( !strcmp(ptr,"THIN") ) {
                        return( WithinTok );
                    }
                    break;

                case('R'):
                    if( !strcmp(ptr,"ITE") ) {
                        return( WriteTok );
                    }
                    break;

            }
            break;

      /*
        X                    XTok
        XYZ                  XYZTok
      */

        case('X'):
            switch(*ptr++) {
                case(0):
                    return( XTok );

                case('Y'):
                    if( (*ptr=='Z') && !ptr[1] ) {
                        return( XYZTok );
                    }
                    break;

            }
            break;

      /*
        Y                    YTok
        YELLOW               YellowTok
        YELLOWTINT           YellowTintTok
      */

        case('Y'):
            switch(*ptr++) {
                case(0):
                    return( YTok );

                case('E'):
                    if( !strcmp(ptr,"LLOW") ) {
                        return( YellowTok );
                    } else if( !strcmp(ptr,"LLOWTINT") ) {
                        return( YellowTintTok );
                    }
                    break;

            }
            break;

      /*
        Z                    ZTok
        ZAP                  ZapTok
        ZOOM                 ZoomTok
      */
        case('Z'):
            switch(*ptr++) {
                case(0):
                    return( ZTok );

                case('A'):
                    if( (*ptr=='P') && !ptr[1] ) {
                        return( ZapTok );
                    }
                    break;

                case('O'):
                    if( !strcmp(ptr,"OM") ) {
                        return( ZoomTok );
                    }
                    break;

            }
            break;

    }
    return( IdentTok );
}
