import random

most_pop = [
#MICKIEWICZ
['Wojski',0],
['Tadeusz',0],
['Klucznik',0],
['Telimena',0],
['Robak',0],
['Gerwazy',0],
['Podkomorzy',0],
['Zosia',0],
['Sedziego',0],
['Tadeusza',0],
['Litwie',0],
['Rejent',0],
['Asesor',0],
['srod',0],
['Rykow',0],
['wtenczas',0],
['Hrabiego',0],
['Horeszkow',0],
['Hrabia,',0],
['Jacek',0],
['Rzekl',0],
['Maciej',0],
['Telimena,',0],
['Tadeusz,',0],
['Soplicow',0],
['Sedzia,',0],
['Wojskiego',0],
['Plut',0],
['Tadeusza,',0],
['Zosi',0],
['Chrzciciel',0],
['ksiedza',0],
['Sedziemu',0],
['Maciek',0],
['Kropiciel',0],
['Soplicowie',0],
['Podkomorzy,',0],
['Stolnik',0],
['Wojski,',0],
['Zosi,',0],
['kedy',0],
['Robak,',0],
['charty',0],
['Moskali,',0],
['Widac,',0],
['Dobrzynscy',0],
['Macka',0],
['rapier',0],
['Gerwazy,',0],
['Dabrowski',0],
['Srod',0],
['Daremnie',0],
['niebios',0],
['Protazy',0],
['rzecze',0],
['Dobrzynski',0],
['Rykow,',0],
['Bernardyn',0],
['jegrow',0],
['Telimeny',0],
['Konewka',0],
['Soplica',0],
['tem,',0],
['By',0],
['biezy',0],
['Iz',0],
['Rejentem',0],
['Moskal',0],
['wtenczas,',0],
['folwarku',0],
['pono',0],
['Hrabie',0],
['litewskich',0],
['pacierz',0],
['jegry',0],
['Jankiel',0],
['Klucznik,',0],
['krzykneli',0],
['Ktorych',0],
['kwestarz',0],
['szable',0],
['wszerz',0],
['Stoja',0],
['Sedzio,',0],
['Wtenczas',0],
['ochmistrzyni',0],
['wiwat',0],
['zrecznie',0],
['"Wiwat',0],
['polskie',0],
['pleban',0],
['Moskalow',0],
['Asesor,',0],
['powiecie,',0],
['Stolnik,',0],
['Dawal',0],
['Kedy',0],
['trawy',0],
['Litwa',0],
['Buchman,',0],
['mysliwcow',0],
['Darmo',0],
['Strzelcy',0],
['zewszad',0],
['nazbyt',0],
['sprzet',0],
['Telimene',0],
['Rejent,',0],
['strzelcy,',0],
['Hrabiemu',0],
['Soplica,',0],
['Dobyl',0],
['Prusak',0],
['strzelcy',0],
['Sak',0],
['owad',0],
['Zosie,',0],
['publico',0],
['Soplicom',0],
['Oj',0],
['Maciej,',0],
['Macieja',0],
['Protazy,',0],
['Protazy.',0],
['obie,',0],
['Jacek,',0],
['Ktorego',0],
['szabli',0],
['krzyczac:',0],
['wytknal',0],
['mysliwi',0],
['zwawo',0],
['Telimenie',0],
['drazki',0],
['Reka',0],
['bokiem,',0],
['Dobrzynskich',0],
['rzed',0],
['wloscian',0],
['konopie',0],
['Asesora',0],
['zwan',0],
['bernardyn',0],
['Zosie',0],
['ptastwo',0],
['Brzytwa',0],
['Polak,',0],
['Chrzciciela',0],
['Skoluba',0],
['Podkomorzego',0],
['Wre',0],
['car',0],
['obadwa',0],
['rury',0],
['Jacka',0],
['Dano',0],
['lowach',0],
['Polski',0],
['Rykowa,',0],
['Soplicowa',0],
['zawzdy',0],
['Dabrowski,',0],
['dworu,',0],
['zdala',0],
['wrzask',0],
['smyk',0],
['Sokol',0],
['Hrabio,',0],
['Pyta',0],
['Moskala,',0],
['bernardyna',0],
['Macieju,',0],
['Litwie,',0],
['"Prawda',0],
['Moskali.',0],
['mysliwych',0],
['Brzytewka',0],
['Rymsza',0],
['Kropidlo',0],
['lowy.',0],
['mlodz',0],
['lisciem',0],
['Soplice!"',0],
['Podkomorzym',0],
['wyjdz',0],
['Buchman',0],
['oblawa,',0],
['prosi.',0],
['karczma',0],
['karczmy',0],
['ubranie',0],
['Ostatniego',0],
['Bartek',0],
['Biega',0],
['Szeroko',0],
['zascianku,',0],
['szlachcie',0],
['wasc',0],
['Jegry',0],
['Wojna',0],
['klosem',0],
['Glupim',0],
['skoczyli',0],
['miodowego',0],
['luba',0],
['Geste',0],
['Gesto',0],
['zadrzy,',0],
['straza.',0],
['skoczyl;',0],
['Odkryte;',0],
['zawiazka;',0],
['Glupi,',0],
['ziecia,',0],
['zwierciadlana',0],
['bzyknie,',0],
['odglosem',0],
['czyjez',0],
['lotu',0],
['wypogadza.',0],
['rozslawisz',0],
['Moskali,',0],
['wezmij',0],
['Wdzieczna',0],
['rozpuszczonych',0],
['Moskali:',0],
['Moskali;',0],
#SIENKIEWICZ
['Winicjusz',1],
['Petroniusz',1],
['albowiem',1],
['Ligia',1],
['cezar',1],
['Nero',1],
['Winicjusza',1],
['Ligii',1],
['Winicjusz.',1],
['Chilo',1],
['cezara',1],
['cezara,',1],
['Petroniusz.',1],
['Ursus',1],
['Ligie',1],
['Piotr',1],
['Winicjusz,',1],
['Winicjusza,',1],
['Ligii,',1],
['Akte',1],
['Rzym',1],
['cezara.',1],
['Petroniusza',1],
['Ligie,',1],
['Pomponia',1],
['Rzymie',1],
['Apostol',1],
['niemal',1],
['Ligia,',1],
['Petroniusz,',1],
['Cezar',1],
['niewolnikow',1],
['rzeklszy',1],
['Tygellinus',1],
['Aulus',1],
['chrzescijanie',1],
['Petroniusza,',1],
['cezar,',1],
['Ligii.',1],
['Poppea',1],
['Winicjusza.',1],
['atrium',1],
['Chilona',1],
['Ancjum',1],
['Pomponii',1],
['bogowie',1],
['Winicjuszowi',1],
['Chilon',1],
['Zali',1],
['Rzymu',1],
['Nerona',1],
['Eunice',1],
['odrzekl:',1],
['niewolnicy',1],
['naokol',1],
['Go',1],
['Eunice,',1],
['Tygellin',1],
['niewolnikow,',1],
['Akte,',1],
['Glauka',1],
['Rzymu,',1],
['uczynil',1],
['Ligia.',1],
['Glaukus',1],
['Chilo.',1],
['Nero.',1],
['Grek',1],
['Ligie.',1],
['Aulusow,',1],
['Nero,',1],
['czynil',1],
['Ostrianum,',1],
['Apostola',1],
['Tygellina',1],
['chrzescijan.',1],
['Aulusow',1],
['uczynic',1],
['Ancjum,',1],
['Via',1],
['Ursus,',1],
['Nerona,',1],
['Linus',1],
['jest!',1],
['Chilo,',1],
['Ursusa',1],
['Nazariusz',1],
['arene',1],
['Ostrianum',1],
['Pomponii,',1],
['Kryspus',1],
['cezarowi',1],
['odrzekla',1],
['Lig',1],
['atrium,',1],
['Tarsu',1],
['Akte.',1],
['arenie',1],
['Chrystusa.',1],
['zali',1],
['Rzymie.',1],
['Ligio,',1],
['Tarsu,',1],
['chrzescijaninem,',1],
['chrzescijanie,',1],
['augustianow,',1],
['ogrodach',1],
['pretorianow',1],
['willi',1],
['Apostola,',1],
['Ligio!',1],
['Krotona,',1],
['pewien,',1],
['niewolnik',1],
['Poppei,',1],
['Winicjuszowi,',1],
['Kroto',1],
['arenie,',1],
['meki',1],
['Palatynie',1],
['cyrku',1],
['cezar.',1],
['Porta',1],
['cezarze,',1],
['Chilon.',1],
['amfiteatrze',1],
['Apostol,',1],
['cisza',1],
['odnalezc',1],
['Winicjuszem',1],
['cubiculum',1],
['Ancjum.',1],
['Ursusa.',1],
['przeto',1],
['trybun',1],
['Mu',1],
['rozkoszy',1],
['centurion',1],
['niewolnicy,',1],
['Ostrianum.',1],
['Chilona.',1],
['glosow.',1],
['czynic',1],
['Chryzotemis',1],
['Petroniuszowi',1],
['Glauka,',1],
['Aulusa',1],
['Petroniuszu,',1],
['Tuliusz',1],
['Vicus',1],
['Krotona',1],
['Eunice.',1],
['nieprzyjaciolmi',1],
['Ursus.',1],
['Greka',1],
['pretorianow,',1],
['Winicjusza:',1],
['augustianie',1],
['Nerona.',1],
['Chilona,',1],
['wiary',1],
['areny,',1],
['slusznosc,',1],
['ogrodow',1],
['jeno',1],
['rzymski',1],
['Apostol.',1],
['Seneka,',1],
['Apostola.',1],
['Achai.',1],
['boski',1],
['cyrku,',1],
['Miedzianobrody',1],
['kazal.',1],
['zaniechawszy',1],
['naloznica,',1],
['naloznica.',1],
['kazal?',1],
['uslucham,',1],
['sposobami.',1],
['zmagajacych',1],
['ocalic?',1],
['lotrze',1],
['Piecdziesiat,',1],
['nagania',1],
['Jakuba,',1],
['slucham',1],
['oklasow.',1],
['frigidarium,',1],
['strate',1],
['przypasujac',1],
['"domina",',1],
['powszechny,',1],
['grzmial.',1],
['Teoklesa',1],
['zmieszanie',1],
['krzyczano',1],
['wyniszczona',1],
['sluchania',1],
#PRUS
['Wokulski',2],
['Wokulski.',2],
['Izabela',2],
['Wokulskiego',2],
['rubli',2],
['baron',2],
['Ignacy',2],
['Rzecki',2],
['Stach',2],
['Wokulski,',2],
['Izabela.',2],
['baronowa',2],
['Wokulskiego.',2],
['Ochocki',2],
['Starski',2],
['Izabeli',2],
['Wasowska',2],
['Wokulskiemu',2],
['rubli,',2],
['Szlangbaum',2],
['Wokulskiego,',2],
['Stawska',2],
['wtedy',2],
['Szuman',2],
['Rzecki.',2],
['ale...',2],
['Lecki',2],
['Ochocki.',2],
[';',2],
['Wasowska.',2],
['prezesowa',2],
['hrabina',2],
['Ignacy.',2],
['Izabeli.',2],
['Alez',2],
['Maruszewicz',2],
['Baron',2],
['Rzecki,',2],
['odparla',2],
['adwokat',2],
['Klejn',2],
['fotelu',2],
['Stawskiej',2],
['Naturalnie,',2],
['Geist',2],
['Mraczewski',2],
['doktor',2],
['rubli...',2],
['sklepu,',2],
['Wokulskim',2],
['Izabele',2],
['Florentyna',2],
['baronowej',2],
['Krzeszowska',2],
['Izabeli,',2],
['Tomasz.',2],
['myslal.',2],
['szepnal.',2],
['Stawskiej,',2],
['rubli.',2],
['Stawka',2],
['baronowa.',2],
['wtracila',2],
['?...',2],
['Lisiecki',2],
['Izabela,',2],
['Geist.',2],
['klacz',2],
['Mincel',2],
['Stanislawie',2],
['Szuman.',2],
['Stawska.',2],
['subiekt',2],
['?',2],
['pan...',2],
['odparl.',2],
['Stacha',2],
['baron,',2],
['a!...',2],
['Misiewiczowa',2],
['przedpokoju',2],
['doktor.',2],
['ze...',2],
['Suzin',2],
['to?...',2],
['Wokulski...',2],
['baron.',2],
['radca',2],
['tysiecy...',2],
['tak...',2],
['spytalem.',2],
['ja...',2],
['procent',2],
['Florentyna.',2],
['adwokat.',2],
['sklepu.',2],
['rzadca.',2],
['kamienice',2],
['staruszka',2],
['doktora',2],
['Starski.',2],
['stosunki',2],
['pan?',2],
['hrabiny',2],
['Doktor',2],
['sklepie,',2],
['Wokulskim.',2],
['prezesowa.',2],
['salonie',2],
['sklep,',2],
['Krzeszowskiej',2],
['Stawskiej.',2],
['prezesowej',2],
['Ignacy,',2],
['Mikolaj',2],
['A,',2],
['diabli',2],
['Wegielek',2],
['Helunia',2],
['Katz,',2],
['Pomimo',2],
['baronowej,',2],
['spolki',2],
['Rzeckiego',2],
['Franc',2],
['Dlaczegoz',2],
['pana...',2],
['kobiete',2],
['ksiaze.',2],
['Wyobraz',2],
['myslal:',2],
['hrabina.',2],
['e',2],
['Starski,',2],
['Szlangbauma',2],
['Jednoczesnie',2],
['Ochocki,',2],
['Wokulskiemu,',2],
['Meliton',2],
['Izabele.',2],
['mezczyzna',2],
['Cha!',2],
['powozu',2],
['fotelu.',2],
['pan?...',2],
['Felicja',2],
['nas...',2],
['szescdziesiat',2],
['alez',2],
['adwokata',2],
['Alez,',2],
['Wirski',2],
['Izabele,',2],
['Wokulskim,',2],
['Przepraszam',2],
['rozmawiala',2],
['baba',2],
['rumieniac',2],
['bilet',2],
['pietnascie',2],
['nic...',2],
['Lecka',2],
['Krzeszowski',2],
['Maruszewicz,',2],
['Ignacego',2],
['cha!...',2],
['domu...',2],
['kamienicy',2],
['szanowny',2],
['spolka',2],
['barona,',2],
['Raczek',2],
['Ewelina',2],
['kobiete,',2],
['barona.',2],
['Katz',2],
['Paryzu',2],
['Geista',2],
['podmuch,',2],
['ciotka...',2],
['Invalides,',2],
['uspokajal',2],
['strzepujac',2],
['L.',2],
['1853."',2],
['musialbys',2],
['utrzymanie.',2],
['Milerowej,',2],
['Przyjemnej',2],
['Blada',2],
['nieograniczenie',2],
['znajomych....',2],
['szpakowatym',2],
['niecalych',2],
['"Te',2],
['zajmiesz',2],
['Polglowek!...',2],
['duszkiem.',2],
['"Czyzem',2],
['pogladach',2],
['kostiumu',2],
['chustce',2],
['mizerny',2],
['szczescie?..',2],
['mizerne',2],
['profesorem',2],
['mizerna',2]
        ]
#random.shuffle(most_pop)

T = int(input())

for i in range(0,T):
    x = str(input()).split()
    odp=False
    for word in most_pop:
        if(word[0] in x):
            if(word[1]==0): print("Mickiewicz")
            elif(word[1]==1): print("Sienkiewicz")
            else: print("Prus")
            odp=True
            break
    if(odp == False):
        r = random.randint(1,3)
        if(r==1): print("Mickiewicz")
        elif(r==2): print("Sienkiewicz")
        else: print("Prus")

