<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 25.01.2017
  Time: 18:55
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
        <title>Pasif İlanlar</title>
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

            $(document).on("click", ".open-delete", function (e) {
                e.preventDefault();
                var _self = $(this);
                var annId = _self.data('id');
                $("#annId").val(annId);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="delete" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">İlanı Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="annId" id="annId">
                            <input formaction="../deleteannouncement" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Sadece pasif olan ilanlar silinebilir. </p>
                        <p>Bu işlem geri alınamaz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="choosePacketDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">

                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">İlanınızı Yayınlayın!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Kullanmak istediğiniz paketi seçiniz</p>

                        <table class="table table-striped">
                            <thead>
                                <tr>
                                    <th>Paket adı</th>
                                    <th>Kalan ilan sayısı</th>
                                    <th>Bir ilanın yayın süresi</th>
                                    <th>Son Kullanma Tarihi</th>
                                    <th>Seç</th>
                                </tr>
                            </thead>
                            <tbody>
                                <tr>
                                    <td>
                                        <form action="../useanannouncement" method="post">
                                            <c:forEach var="packet" items="${availablepackets}" varStatus="myIndex">
                                                <c:if test="${packet.packet.announcementCount > packet.usedAnnouncements}">
                                                    <tr>
                                                        <td>${packet.packet.title}</td>
                                                        <td>${packet.packet.announcementCount - packet.usedAnnouncements}</td>
                                                        <td>${packet.packet.activeTime}</td>
                                                        <td>${packet.packet.lastDateUsed}</td>
                                                        <td><button class="btn btn-default" name ="ap" type="submit" value="${packet.id}">Seç</button></td>
                                                    </tr>
                                                </c:if>
                                            </c:forEach>
                                            <input type="hidden" name="ann" id="announcementId" value="">
                                        </form>
                                    </td>
                                </tr>
                            </tbody>
                        </table>
                    </div>
                    <div class="modal-footer">
                        <p>Bir ilan aynı anda bir paketten yayında olabilir.
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
                        <c:when test="${ilanaktif eq 1 }">
                            <div class = "alert alert-success">
                                İlan aktif edildi. <br/>
                                İlana <a href="../myactiveannouncements">buradan</a> erişebilirsiniz.
                            </div>
                        </c:when>
                        <c:when test="${ilansil eq 1 }">
                            <div class = "alert alert-success">
                                İlan silindi.
                            </div>
                        </c:when>
                        <c:when test="${ilansil eq 2 }">
                            <div class = "alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                        <c:when test="${ilanaktif eq 2 }">
                            <div class = "alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>

                    <h4><strong>Pasif İlanlarınız</strong></h4>
                    <table class="table table-hover">
                        <thead>
                        <tr>
                            <th>İlan No</th>
                            <th>Başlık</th>
                            <th>Durum</th>
                            <th>Başvuru Sayısı</th>
                            <th>İşlem</th>
                        </tr>
                        </thead>
                        <tbody>
                        <c:if test="${fn:length(announcements) eq 0}">
                            <tr>
                                <td><i>Pasif ilanınız yok.</i></td>
                            </tr>
                        </c:if>
                        <c:forEach var="item" items="${announcements}">
                            <tr>
                                <td>${item.id}</td>
                                <td>${item.title}</td>
                                <td>${item.state.title}</td>
                                <td>${item.numberOfPageViews}</td>
                                <td>
                                    <form method="post">
                                        <input type="hidden" name="packetId" value="${item.id}" />
                                        <a  href="../updateannouncement?annId=${item.id}"
                                            title="Düzenle"
                                            class="l btn btn-success">
                                            <span class="glyphicon glyphicon-pencil"/>
                                        </a>

                                        <a data-id="${item.id }" data-toggle="modal" title="Yayına Al" class="open-ChoosePacketDialog btn btn-primary" href="#choosePacketDialog">
                                            <span class="glyphicon glyphicon-ok"></span>
                                        </a>
                                        <a href="#delete" data-id="${item.id }" title="Sil" data-toggle="modal" class="open-delete btn btn-danger">
                                            <span class="glyphicon glyphicon-trash"></span>
                                        </a>
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

