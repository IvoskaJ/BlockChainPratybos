# BlockChainPratybos
Repozitorija skirta blockchain tehnologiju pratyboms

   2021/09/13 pirmas commitas, pradetas daryti pirmas laboratorinis darbas
   
   2021/09/19 antras commitas, patobulinta hash funkcija
   
   2021/09/22 trecias commitas, dar pakeista hash funkcija, pridetas pasirinkimas naudoti duomenis paimtus is failo
   
   2021/09/27 ketvirtas commitas, (turbut) galutinai sutvarkyta hash funkcija, padarytas teisingas outputas, pridetos funkcijos skirtos tobulinti programos naudojima.
   
   2021/09/27 penktas commitas, ideta galimybe palyginti hash funkcija su sha256, ir md5, collisionu tikrinimas
   
   2021/09/29 sestas commitas, ideta galimybe patikrinti gaunamu hashu panasumus bitu ir hex'o lygmenyje.
   
   eksperimentiniai tyrimai-analize:
   
   
   1.Susikurkite testinių įvedimo failų pavyzdžių, tokių kad:
   Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio.
   Bent du failai būtų sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių.
   Bent du failai būtų sudaryti iš daug (> 1000) simbolių, bet skirtųsi vienas nuo kito tik vienu (pvz. vidurinėje pozicijoje     esančiu) simboliu.
   Tuščio failo.
   
   ![image](https://user-images.githubusercontent.com/78845735/135328470-0ca3d447-a400-455c-8b6a-26def41c1084.png)


   2.  Naudojant šiuos failus, kaip Jūsų programos input'us, įsitikinkite, kad Jūsų hash funkcija atitinka 1-3-ą reikalavimus, t.y., nepriklausomai nuo Input'o, Output'ai visada yra vienodo dydžio, o to paties failo hash'as yra tas pats.
   
   ![image](https://user-images.githubusercontent.com/78845735/135328815-d3b8c821-7ab5-49e2-9db9-2d34faa7becd.png)


   3.  Ištirkite Jūsų sukurtos hash funkcijos efektyvumą: tuo tikslu suhash'uokite kiekvieną eilutę iš konstitucija.txt failo ir išmatuokite kiek laiko visa tai užtruko. Reiktų matuoti, tik hash'avimo funkcijos veikimo laiką (be input'o nuskaitymo/parengimo). Reiktų pateikti bendrą suminį visų hash'avimų laiką.
   Papildoma užduotis - norintiems užsidirbti extra balų (iki 0.5). Pabandykite kaip įmanoma objektyviau palyginti Jūsų Hash funkcijos spartą su  MD5 ,  SHA-1 ,  SHA-256  ar kita gerai žinoma hash funkcija. Paliekame Jums sugalvoti, kaip atlikti tokį palyginima kaip įmanoma objektyviau.
   
   hashas su konstitucija:
   ![image](https://user-images.githubusercontent.com/78845735/135329097-c9b9a584-702c-41d2-9bb5-dbbc086bba92.png)
   
   
   papildoma uzd.
   
   
   ![image](https://user-images.githubusercontent.com/78845735/135329245-560ff63d-59e8-4755-9027-1e941b9d68f9.png)
   
   
   lyginama buvo su dideliu failu pilnu random symboliu, kadangi md5 ir sha256 implementacijos (kurios buvo paimtos is interneto) veike taip greitai, kad dazniausia matuojant kiek laiko uztrunka uzhashinti konstitucija.txt, laikas buvo gaunamas 0
   taigi is tyrimo akivaizdu, kad parasyta hash funkcija yra labai leta, palyginus su md5 ir sha256


   4.  Susigeneruokite bent 100 000 atsitiktinių simbolių eilučių ( string 'ų) porų, pvz. (asdfg, hijkl), apsiribojant iki 1000 simbolių ilgiu. Toje pačioje poroje esančių string'ų ilgiai turi sutapti, tačiau skirtingos poros gali būti skirtingo ilgio. Rekomenduojame susigeneruoti taip: 25000 porų, kurių ilgis 10 simbolių, kitas 25 000 porų, kurių ilgis - 100, dar kitas 25 000 poras - 500, ir galiausiai likusias 25 000 poras, kurių ilgis - 1000 simbolių.


5.  Tuomet naudodami šias sugeneruotas poras, patikrinkite, ar tikrai visais atvejais gautieji porų hash'ai nesutampa. O jeigu sutampta, tai kaip dažnai tai nutinka ir galbūt pabandykite ištaisyti programos realizaciją, kad to išvengti. Tokiu būdu (jeigu tikrai visuomet hash'ai nesutampa) bent dalinai įsitikinsite, kad Jūsų hash funkcija atitinka 6-ą reikalavimą (atsparumą kolizijai)
   
   
   ![image](https://user-images.githubusercontent.com/78845735/135331546-070e8b07-9450-479b-b0b1-f066634ca387.png)

