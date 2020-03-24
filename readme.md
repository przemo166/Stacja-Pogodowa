# Kurs IO LAB , rok akademicki 2019/20 .

|  Temat projektu : | Stacja pogodowa  |
| :------------: | :------------: |
|  Autorzy :  |  Przemys砤w Widz , Oskar Wi阠kowicz   |
| Prowadz筩y :  | Mgr inz. Wojciech Tarnawski  |
|  Data oddania :  | 14.01.2020r.  |
|  Termin zaj赕 :   |  PIATEK/TP 14:30 - 17:30 | 

![Zdj臋cie projektu ](projekt.png "fig:") [fig:my~l~abel]

Za艂o偶enia projektowe
====================

Celem projektu by艂o stworzenie prostej stacji pogodowej, powiadamiaj膮cej
u偶ytkownika o nast臋puj膮cych informacjach :

1.  bie偶膮cy czas i data

2.  temperatura powietrza pochodz膮ca z dw贸ch osobnych czujnik贸w

3.  ci艣nienie atmosferyczne

4.  wilgotno艣膰 powietrza

Do stacji pomiarowej dodano r贸wnie偶 modu艂 Bluetooth umo偶liwiaj膮cy zdalne
wysy艂anie bie偶膮cych danych z czujnik贸w na komputer lub smartfon.

U偶yte elementy
==============

![Zdj臋cia element贸w u偶ytych do projektu ](elementy.png "fig:")
[fig:my~l~abel]

**Do przygotowania stacji pogodowej u偶yto nast臋puj膮cych element贸w :**

-   **Klon Arduino Uno** (do wst臋pnego projektu na p艂ytce stykowej)

    Arduino Uno to popularna p艂ytka z mikrokontrolerem ATmega328 z
    rodziny AVR wyposa偶ony w 14 cyfrowych wej艣膰/wyj艣膰 z czego 6 mo偶na
    wykorzysta膰 jako wyj艣cia PWM oraz 6 analogowych wej艣膰.

-   **Klon Arduino Nano** (do projektu ko艅cowego)

    Arduino Nano to popularna wersja Uno w mniejszym rozmiarze: 45 x 18
    mm. P艂ytka zawiera mikrokontroler ATmega328 wyposa偶ony w 22 cyfrowe
    wej艣cia/wyj艣cia z czego 6 mo偶na wykorzysta膰 jako wyj艣cia PWM oraz 8
    jako wej艣cia analogowe.

-   **Wy艣wietlacz LCD 2x20**

    Popularny wy艣wietlacz 2 x 20 znak贸w pod艣wietlany w kolorze
    niebieskim.

-   **Czujnik temperatury i wilgoci DHT22**

    Czujnik temperatury i wilgotno艣ci powietrza z interfejsem cyfrowym,
    jednoprzewodowym. Zakres pomiarowy: temperatura -40 do 80 掳C,
    wilgotno艣膰 0-100 %RH.

-   **Modu艂 bluetooth HC-05**

    Modu艂 Blootooth v2.0 + EDR klasa 2. Pracuje z napi臋ciem 3,3 V,
    komunikuje si臋 poprzez interfejs szeregowy UART (piny RX, TX),
    wspiera komendy AT. Maksymalna moc nadajnika wynosi + 4 dBm, czu艂o艣膰
    odbiornika to - 85 dBm. Modu艂 Bluetooth pozwala na po艂膮czenie
    dowolnego urz膮dzenia z telefonem, smartfonem, tabletem lub innym
    urz膮dzeniem bezprzewodowo.

-   **Czujnik ci艣nienia atmosferycznego i temperatury BMP280**

    Modu艂 z cyfrowym barometrem firmy Bosch BMP180. Zakres pomiarowy
    wynosi od 200 do 1100 hPa z dokonano艣ci膮 0,02 hPa. Zasilany jest
    napi臋ciem z zakresu 1,8 - 3,6 V.

-   **Zegar czasu rzeczywsitego RTC DS1307**

    Modu艂 z zegarem czasu rzeczywistego i rezerwowym zasilaniem
    bateryjnym, kt贸re ma na zadanie podtrzymanie pracy zegara po zaniku
    g艂贸wnego zasilania uk艂adu. Pozwala na odczyt czasu w postaci
    godziny, minuty i sekundy oraz daty: miesi膮c, dzie艅, rok.
    Interfejsem komunikacyjnym jest magistrala I2C.

-   **Potencjometr 10k**

    Rezystor nastawny, kt贸ry dzia艂a na zasadzie klasycznego dzielnika
    napi臋cia. Typowym zastosowaniem potencjometr贸w jest regulacja pr膮du
    lub napi臋cia w urz膮dzeniach elektrycznych. W tym przypadku zosta艂
    u偶yty do regulacji kontrastu w wy艣wietlaczu LCD.

-   **Bateria 9V**

    Bateria u偶yta do samodzielnego zasilania stacji pogodowej.

Dzia艂anie stacji pogodowej
==========================

Stacja pogodowa dokonuje pomiar贸w wilgotno艣ci, temperatury, ci艣nienia
atmosferycznego oraz czasu. Nast臋pnie wyniki pomiar贸w pokazywane s膮 na
wy艣wietlaczu LCD oraz przesy艂ane przez bluetooth na telefon lub komputer
i wy艣wietlane na nich za pomoc膮 aplikacji Bluetooth Terminal.

Wy艣wietlanie danych na wy艣wietlaczu odbywa si臋 co dwie sekundy, w
kolejno艣ci zgodnej z p臋tl膮 g艂贸wn膮 programu :

-   temperatury (z obu czujnik贸w)

-   ci艣nienie i wilgotno艣膰

-   data i czas

Zatem czas trwania p臋tli to 6 sekund (3 x 2 sekundy), zako艅czone
wys艂aniem danych na komputer lub smartfon.

![Przyk艂adowy cykl pracy wy艣wietlacza ](cykl.PNG "fig:") [fig:my~l~abel]

![Przesy艂 danych na komputer (z lewej) oraz telefon (z prawej)
](lol.PNG "fig:") [fig:my~l~abel]

Przebieg realizacji projektu
============================

Prototyp stacji pogodowej by艂 realizowany na p艂ytce stykowej przy pomocy
Arduino Uno. Budowe stacji pogodowej zacz臋to od pod艂aczenia czujnik贸w do
Arduino oraz stworzenia programu obs艂uguj膮cego je. Nastepnie dodany
zosta艂 wy艣wietlacz LCD, na kt贸rym zosta艂y wy艣wietlone dane pomiarowe.
Kolejnym etapem by艂a realizacja komunikacji bezprzewodowej przy pomocy
modu艂u bluetooth oraz zasilanie z baterii. Nast臋pnie, gdy prototypowa
stacja pogodowa dzia艂a艂a poprawnie, zamieniono Ardunino Uno na Arduino
Nano w celu zaoszcz臋dzenia miejsca na uniwersalnej p艂ytce PCB, do kt贸rej
przylutowane zosta艂y wszystkie elementy.

Podczas realizacji projektu napotkano kilka problem贸w. Jednym z nich by艂
niedzia艂aj膮cy wy艣wietlacz LCD, na kt贸rym mia艂y by膰 wy艣wietlane dane
pomiarowe. Okaza艂o si臋, 偶e z艂膮cza m臋skie dzi臋ki, kt贸rym mozna umie艣ci膰
wy艣wietlacz na p艂ytce stykowej nie by艂y do niego przylutowane przez co
jaki艣 element nie styka艂. W pierwotnym projekcie bezprzewodowa
komunikacja stacji pogodowej mia艂a by膰 realizawana za pomoc膮 wifi.
Zakupiono wi臋c modu艂 ESP8266, jednak napotkano problemy, kt贸rych nie
uda艂o si臋 rozwi膮za膰. W efekcie bezprzewodow膮 komunikacj臋 zrealizowano
przy pomocy modu艂u bluetooth HC-05, kt贸ry pozwala przesy艂a膰 dane na
telefon. Dane odebrane ze stacji pogodowej wy艣wietlane s膮 w aplikacji
Bluetooth Terminal.

Arduino zapewnia gotowe biblioteki przez co programowanie
mikrokontrolera jest programowaniem wysokopoziomowym, a co za tym idzie
du偶o przyjemniejszym i prostszym. Ka偶dy modu艂 u偶yty w projekcie mia艂
swoje dedykowane biblioteki, dzi臋ki czemu w kodzie 藕r贸d艂owym pos艂ugiwano
si臋 obiektami gotowych klas.

Schemat po艂膮cze艅
================

![Schemat po艂膮cze艅 element贸w stacji pogodowej ](schemat.jpg "fig:")
[fig:my~l~abel]

Kosztorys projektu
==================

1.  Arduino Nano klon - **21.00 z艂**

2.  P艂ytka uniwersalna 鈥淯-11鈥� - **element z laboratorium**

3.  Czujnik DHT22 - **22.00 z艂**

4.  Wy艣wietlacz LCD - **17.50 z艂**

5.  Czujnik BMP280 - **12.00 z艂**

6.  Rezystor 10k - **0.05 z艂**

7.  Zegar czasu rzeczywistego RTC DS1307 - **11.60 z艂**

8.  Bateria 9V - **5.00 z艂**

9.  Modu艂 bluetooth HC-05 - **22.30 z艂**

10. Potencjometr - **3.00 z艂**

**Ca艂kowity koszt stacji pogodowej - 114.45 z艂**\

Wnioski
=======

-   Budowa stacji pogodowej jest czasoch艂onnym zaj臋ciem. Ma艂y b艂膮d mo偶e
    kosztowa膰 nawet kilka godzin pracy. Jednak podczas realizacji tego
    projektu mo偶na si臋 nauczy膰 wiele praktycznych rzeczy z dziedziny
    elektroniki i programowania.

-   Najtrudniejszym etapem okaza艂a si臋 realizacja odpowiednich po艂膮cze艅
    elektrycznych pomiedzy poszczeg贸lnymi elementami stacji pogodowej.
    Natomiast najprostszym etapem by艂o programowanie.

-   Por贸wnuj膮c koszt zbudowania stacji pogodowej z cen膮 takiego
    urz膮dzenia zakupionego w sklepie elektronicznym mo偶na doj艣膰 do
    wniosku, 偶e czasami warto jest zrealizowa膰 jaki艣 projekt samemu i
    zaoszcz臋dzi膰 pieni膮dze. Koszt stacji wyni贸s艂 114,45z艂, gdzie w
    sklepie elektronicznym trzeba zap艂aci膰 艣rednio 150z艂. Zamawiaj膮c
    elementy do budowy stacji z Chin, a nie od Polskich po艣rednik贸w,
    mo偶na by by艂o zaoszcz臋dzi膰 jeszcze wi臋cej.


