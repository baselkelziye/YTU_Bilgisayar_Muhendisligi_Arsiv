<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 25.01.2017
  Time: 22:11
  To change this template use File | Settings | File Templates.
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <title>Cezalı İlanlar</title>
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
                    <h4><strong>Cezalı İlanlarınız</strong></h4>
                    <table class="table table-hover">
                        <thead>
                        <tr>
                            <th>İlan No</th>
                            <th>Başlık</th>
                            <th>Paket(Varsa)</th>
                            <th>Şikayet Sayısı</th>
                            <th>İşlem</th>
                        </tr>
                        </thead>
                        <tbody>
                            <c:if test="${fn:length(announcements) eq 0}">
                                <tr>
                                    <td><i>Cezalı ilanınız yok.</i></td>
                                </tr>
                            </c:if>
                            <c:forEach var="item" items="${announcements}">
                                <tr>
                                    <td>${item.id}</td>
                                    <td>${item.title}</td>
                                    <td>${item.ownerPacket.packet.title}
                                    <td>${fn: length(item.complaintList)}</td>
                                    <td>
                                        <a  href="#detail"
                                            title="Detay"
                                            data-toggle="modal"
                                            data-title="${item.title}"
                                            data-content="${item.content}"
                                            data-brief="${item.brief}"
                                            data-publish="${item.publishDate}"
                                            class="open-detail btn btn-success">
                                            <span class="glyphicon glyphicon-th"></span>
                                        </a>
                                        <a  href="#complaintMessage"
                                            data-toggle="modal"
                                            title="Ceza Sebebi"
                                            class="complaint-message btn btn-primary"
                                            data-message="${item.complaintList[0].resultReply}">
                                            <span class="glyphicon glyphicon-envelope"></span>
                                        </a>
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

