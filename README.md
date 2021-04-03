# IoT1929-PROJE
# RFID ve servo ile kapı kilidi 

Bu projede,
 - Arduino Leonardo 
 - Micro Servo 
 - RFID Kart Okuyucu
 - LCD 16x2 I2C
 - Kırmızı ve yeşil led
 - Jumper kablolar 
 - Breadboard 

kullanarak bir kartlı kapı kilidi yaptık. 

> Projenin amacı herhangi bir kapıyı sadece erişimi olan insanların açabilmesine izin vererek kişisel alanın korunmasını sağlamaktır.

> Tanımlı bir kart okutulunca LCD ekranda "GİRİŞ BAŞARILI. HOŞ GELDİNİZ!" yazısı belirir ve yeşil led yanar. Ardından servo motorun kolu 90 derece dönerek kapının açılmasına izin verir.

> Tanımsız bir kart okutulunca ise LCD ekranda "KART TANIMLANMADI!" uyarısı belirir ve kırmızı led yanar. Servo motor kolu dönmez ve kapı kilitli kalmaya devam eder.

*Henüz bir prototip olması nedeniyle gerçek bir kapıya bağlı değil; ancak basit bir kilit değişimiyle ve arduinoyu bilgisayar yerine bir portatif güç kaynağına bağlayarak kilit aktif olarak kullanılabilir. 
