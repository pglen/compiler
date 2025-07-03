
include 'world.inc'

OBJECT_STATIC = 1
OBJECT_CURSOR = 2
OBJECT_PLAYER = 3

LAYER_BOTTOM = 0
LAYER_MIDDLE = 80h
LAYER_TOP    = 0FFh

ZONE_ILLEGAL = 1
ZONE_EVENT   = 2

EVENT_PLACE  = 1
EVENT_PLAYER = 2
EVENT_TEXT   = 3

dd images
dd pasek_sterowania
dd las
dd start

images:
  image trawa,_trawa1,0,0,480,480
  image trawa_rzadka,_trawa2,0,0,480,480
  image pasek,_pasek,0,0,160,480
  image papier,_papier,23,0,385,420
  image žwistek,_papier,0,438,461,90
  image bohater,_bohater,0,0,48,60,30,46
  image r‘ka,_kursory,42,0,31,22,30,21
  image no§yk,_kursory,0,0,42,25,0,0
  image kamyk_1,_kamycki,25,8,38,17,10,10
  image kamyk_2,_kamycki,25,41,27,14,10,10
  image kamyk_3,_kamycki,34,60,13,11,5,10
  image ga’†¦,_kamycki,105,182,45,21,20,20
  image tabliczka,_kamycki,9,169,52,44,32,34
  image cie¤_tabliczki,_kamycki,9,219,52,44,32,34
  image drzewo_1,_drzewa,76,21,174,170,84,160
  image cie¤_drzewa_1,_drzewa,6,201,164,180,154,176
  image drzewo_2,_drzewa,256,17,177,180,83,166
  image cie¤_drzewa_2,_drzewa,193,206,164,187,146,170
 db 0

pasek_sterowania:
  plane pasek,480,0
  object OBJECT_CURSOR,r‘ka,0,-160,240,LAYER_TOP
 db 0

start:
  event EVENT_TEXT,tekst_pocz†tkowy
 db 0

na_step:
  event EVENT_PLACE,step
  event EVENT_TEXT,tekst_step
 db 0

do_lasu:
  event EVENT_PLACE,las
  event EVENT_PLAYER,wchodz†cy_do_lasu
 db 0

las:
 plane trawa,0,0
  object OBJECT_PLAYER,bohater,0100h,240,240,LAYER_MIDDLE
  object OBJECT_STATIC,kamyk_1,0,440,40,LAYER_BOTTOM
  object OBJECT_STATIC,kamyk_2,0,100,100,LAYER_BOTTOM
  object OBJECT_STATIC,kamyk_3,0,360,400,LAYER_BOTTOM
  object OBJECT_STATIC,ga’†¦,0,120,260,LAYER_BOTTOM
  object OBJECT_STATIC,tabliczka,0,320,300,LAYER_MIDDLE
  object OBJECT_STATIC,cie¤_tabliczki,0,320,300,LAYER_BOTTOM
  object OBJECT_STATIC,drzewo_1,0,300,200,LAYER_MIDDLE
  object OBJECT_STATIC,cie¤_drzewa_1,0,300,200,LAYER_BOTTOM
  object OBJECT_STATIC,drzewo_2,0,170,432,LAYER_MIDDLE
  object OBJECT_STATIC,cie¤_drzewa_2,0,170,432,LAYER_BOTTOM
  object OBJECT_CURSOR,no§yk,0,320,240,LAYER_TOP
 db 0
  zone ZONE_ILLEGAL,0,0,480,45
  zone ZONE_ILLEGAL,0,0,20,480
  zone ZONE_ILLEGAL,0,470,480,10
  zone ZONE_ILLEGAL,460,0,20,480
  zone ZONE_ILLEGAL,280,185,60,25
  zone ZONE_ILLEGAL,150,415,60,25
  zone ZONE_ILLEGAL,295,295,63,20
  zone ZONE_EVENT,0,0,50,50,na_step
 db 0

step:
 plane trawa_rzadka,0,0
  object OBJECT_PLAYER,bohater,0500h,450,450,LAYER_MIDDLE
  object OBJECT_CURSOR,no§yk,0,320,240,LAYER_TOP
 db 0
  zone ZONE_ILLEGAL,0,0,480,45
  zone ZONE_ILLEGAL,0,0,20,480
  zone ZONE_ILLEGAL,0,470,480,10
  zone ZONE_ILLEGAL,460,0,20,480
  zone ZONE_EVENT,450,450,30,30,do_lasu
 db 0

wchodz†cy_do_lasu:
 object OBJECT_PLAYER,bohater,0100h,50,50,LAYER_MIDDLE

tekst_pocz†tkowy:
 text papier,60,60,_start

tekst_step:
 text žwistek,20,50,_step

pliki:
  _bohater db 'data\bohater.gif',0
  _kursory db 'data\kursory.gif',0
  _trawa1 db 'data\trawa1.gif',0
  _trawa2 db 'data\trawa2.gif',0
  _pasek db 'data\deska.gif',0
  _papier db 'data\papier.gif',0
  _kamycki db 'data\kamycki.gif',0
  _drzewa db 'data\drzewa.gif',0
  _start db 'data\start.txt',0
  _step db 'data\step.txt',0
