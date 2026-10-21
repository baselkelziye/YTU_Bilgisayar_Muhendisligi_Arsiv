<%--
    Document   : myannouncements
    Created on : 22.Nis.2016, 23:19:46
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <title>Aktif İlanlar</title>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-ChoosePacketDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var myAnnouncementId = _self.data('id');
                $("#announcementId").val(myAnnouncementId);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".complaint-message", function (e) {
                e.preventDefault();
                var _self = $(this);
                var mes = _self.data('message');
                document.getElementById("message").innerHTML = mes;
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-detail", function (e) {
                e.preventDefault();
                var _self = $(this);

                var title = _self.data('title');
                var content = _self.data('content');
                var brief = _self.data('brief');
                var publish = _self.data('publish');

                document.getElementById("title1").innerHTML = title;
                document.getElementById("content1").innerHTML = content;
                document.getElementById("publish1").innerHTML = publish;
                document.getElementById("brief1").innerHTML = brief;

                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="detail" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <h4>İlan Detayları</h4>

                        <p><b>Başlık</b></p>
                        <p id="title1"></p>

                        <p><b>Kısa Açıklama</b></p>
                        <p id="brief1"></p>

                        <p><b>İçerik</b></p>
                        <p id="content1"></p>

                        <p><b>Şirket Adı</b></p>
                        <p id="company1"></p>

                        <p><b>Yayınlanma Tarihi</b></p>
                        <p id="publish1"></p>

                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="complaintMessage" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <h4>İlanın Kaldırılmasına Yönelik Yönetici Mesajı:</h4>
                        <br/>
                        <p id="message"></p>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-8">
                    <c:choose>
                        <c:when test="${gorunur eq 1 }">
                            <div class = "alert alert-success">
                                İlan durumu görünür olarak değiştirildi.
                            </div>
                        </c:when>
                        <c:when test="${gorunmez eq 1 }">
                            <div class = "alert alert-success">
                                İlan durumu görünmez olarak değiştirildi.
                            </div>
                        </c:when>
                        <c:when test="${gorunmez eq 2 }">
                            <div class = "alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                        <c:when test="${gorunur eq 2 }">
                            <div class = "alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>

                    <h4><strong>Aktif İlanlarınız</strong></h4>
                    <table class="table table-hovered">
                        <thead>
                            <tr>
                                <th>İlan No</th>
                                <th>Başlık</th>
                                <th>Paket</th>
                                <th>Görüntülenme Sayısı</th>
                                <th>Başvuru Sayısı</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:if test="${fn:length(announcements) eq 0}">
                                <tr>
                                    <td><i>Aktif ilanınız yok.</i></td>
                                </tr>
                            </c:if>
                            <c:forEach var="item" items="${announcements}">
                                <tr>
                                    <td>${item.id}</td>
                                    <td>${item.title}</td>
                                    <td>${item.ownerPacket.packet.title}
                                    <td>${item.numberOfPageViews}</td>
                                    <td>${fn:length(item.appStudentList)}</td>
                                    <td>
                                        <form method="post">
                                            <a href="../announcementdetail?packetId=${item.id}" class="btn btn-success" title="Detay">
                                                <span class="glyphicon glyphicon-th"></span>
                                            </a>
                                            <c:choose>
                                                <c:when test="${item.visibility eq true}">
                                                    <a href="../announcementnonvisible?id=${item.id}" class="btn btn-warning" title="Görünmez Yap">
                                                        <span class="glyphicon glyphicon-eye-close"></span>
                                                    </a>
                                                </c:when>
                                                <c:when test="${item.visibility eq false}">
                                                    <a href="../announcementvisible?id=${item.id}" class="btn btn-primary" title="Görünür Yap">
                                                        <span class="glyphicon glyphicon-eye-open"></span>
                                                    </a>
                                                </c:when>
                                            </c:choose>
                                        </form>
                                    </td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>
