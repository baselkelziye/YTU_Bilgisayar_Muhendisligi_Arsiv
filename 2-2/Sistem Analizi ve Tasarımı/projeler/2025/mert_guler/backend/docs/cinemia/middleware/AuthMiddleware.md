# AuthMiddleware

## Amaç
Kullanıcıların giriş bilgilerinin doğrulanması ve Authentication'un sağlnması.

## Middleware
Bir web requestinin spring-controller arasında değerlendirildiği yer.
Bu değerlendirme ile request henüz controllere ulaşmadan bazı doğrulamaları yapabiliyoruz.

## Kullanım
``doFilterInternal`` fonksiyonu önce request'ten tokeni alır:
```java
String token = getTokenFromRequest(request);
```
Daha sonra eğer token mevcut ise token içerisinden `Session`'a erişmeye çalışır.
```java
Session session = sessionManager.getSession(token);
```
Eğer token doğru ve geçerli ise bu session objesi güncellenir (geçerlilik süresi uzatılır) ve kullanıcı bilgileri alınır.
```java
UserPrinciple principle = sessionManager.getPrinciple(session);
```
Eğer principle elde edilmişse bununla beraber request'in içine Authentication işlenir.
```java
UserPrincipleAuthToken auth = new UserPrincipleAuthToken(principle);
SecurityContextHolder.getContext().setAuthentication(auth);
```