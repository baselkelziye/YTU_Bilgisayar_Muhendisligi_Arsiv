<%-- 
    Document   : nasilcalisir
    Created on : 12.May.2016, 01:43:04
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"></jsp:include>
    <title>Nasıl Çalışır</title>
</head>
<body>
    <jsp:include page="html/header.jsp"></jsp:include>

    <div class="text-center">
        <h3>Şirketler</h3>
        <h3>
            Sisteme <a href="sirket-kayit.jsp"> buradan </a>kayıt olun.
            İlanınızı hazırlayın.
            Yönetici tarafından tanımlanan ilan paketlerinden istediğiniz bir 
            tanesine bağış karşılığı sahip olun.
            Hazırladığınız ilanı aktif edin ve öğrenci başvurularını inceleyin.
        </h3>
        <h3>Öğrenciler</h3>
        <h3>
            Sisteme <a href="ogrenci-kayit.jsp"> buradan </a>kayıt olun.
            CV'nizi hazırlayın. İstediğiniz kriterlere göre ilan arayın ve
            istediğiniz ilana başvurun. Şirketler sizinle iletişime geçsin.
        </h3>
    </div>
    <jsp:include page="html/footer.html"/> 
</body>
</html>
