<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 29.12.2016
  Time: 06:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>İlanlarımda Ara</title>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel panel-heading">
                            <p>Arama Kriterleriniz</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action="../searchmyann">
                                <div class="form-group">
                                    <label for="state">İlan Durumu</label>
                                    <!--Bu kısım vt den gelebilir. Şu an için aktifler pasife çevrilemiyor-->
                                    <!--Aktifler için arama now() < expired -->
                                    <select name="state" class="form-control" id="state">
                                        <option value="tümü">Tümü</option>
                                        <option value="aktif">Aktif</option>
                                        <option value="pasif">Pasif</option>
                                        <option value="cezalı">Cezalı</option>
                                        <option value="süresigeçmiş">Süresi Geçmiş</option>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label>Dili</label>
                                    <select name="language" class="form-control" id="language">
                                        <option value="tümü">Tümü</option>
                                        <option value="türkçe">Türkçe</option>
                                        <option value="ingilizce">İngilizce</option>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Ara</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-7">
                    <table class="table table-hovered">
                        <thead>
                            <tr>
                                <th>Başlık</th>
                                <th>Özet</th>
                                <th>Durumu</th>
                                <th>Dil</th>
                                <th>Paket</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${annList}">
                                <tr>
                                    <td>${item.title}</td>
                                    <td>${fn:substring(item.brief, 0, 15)}...
                                        <a href="#" data-toggle="popover" data-placement="left"
                                           title="Açıklama:" data-content="${item.brief}">
                                            <span class="glyphicon glyphicon-info-sign "></span>
                                        </a>
                                    </td>
                                    <td>${item.state.title}</td>
                                    <td>${item.announcementLanguage}</td>
                                    <td>${item.ownerPacket.packet.title}</td>
                                    <td></td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>
