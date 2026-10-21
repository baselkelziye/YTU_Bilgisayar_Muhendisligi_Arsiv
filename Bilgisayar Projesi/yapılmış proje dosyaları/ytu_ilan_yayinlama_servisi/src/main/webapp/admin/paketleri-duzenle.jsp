<%-- 
    Document   : displaypackets
    Created on : 29.Nis.2016, 16:10:21
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <title>Paketleri Gör</title>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-deletePacketDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#id").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-activePacketDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#id2").val(id);
                $(_self.attr('href')).modal('show');
            });
        </script>
        <div class="modal fade" id="deletePacketDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Paket Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Paketi Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="id" id="id">
                            <input formaction="../deletepacket" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="activePacketDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Aktif Hale Getir!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Paketi Görünür Yapmak İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="id" id="id2">
                            <input formaction="../activepacket" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Görünür olan paketler, pasif durumuma çekilemez.</p>
                        <p>Görünür olan paketler silinemez, güncellenemez.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Paket Getir</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action="../searchpacket">
                                <div class="form-group">
                                    <label>Paket Tipi</label>
                                    <div class="radio">
                                        <label><input type="radio" name="type" value="Aktif" checked="checked">Aktif</label>
                                    </div>
                                    <div class="radio">
                                        <label><input type="radio" name="type" value="Pasif">Pasif</label>
                                    </div>
                                    <div class="radio">
                                        <label><input type="radio" name="type" value="Hepsi">Hepsi</label>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label>Durumu</label>
                                    <div class="radio">
                                        <label><input type="radio" name="state" value="Güncel" checked="checked">Güncel</label>
                                    </div>
                                    <div class="radio">
                                        <label><input type="radio" name="state" value="Tarihi Geçmiş">Tarihi Geçmiş</label>
                                    </div>
                                    <div class="radio">
                                        <label><input type="radio" name="state" value="Hepsi">Hepsi</label>
                                    </div>
                                </div>
                                <div class="form-group">
                                    <label for="dau">BKB Seç</label>
                                    <select name="department" id="dau" class="form-control">
                                        <c:forEach var="item" items="${alldau}">
                                            <option value="${item.unitName}">
                                                <c:out value="${item.unitName}"/>
                                            </option>
                                        </c:forEach>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Paketleri Getir</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-8">
                    <a href="../newannouncementpacketservlet" class="btn btn-info">Yeni Paket Ekle</a>
                    <p></p>
                    <c:choose>
                        <c:when test="${paketsil eq 1}">
                            <div class="alert alert-success">
                                Paket başarıyla silindi.
                            </div>
                        </c:when>
                        <c:when test="${paketsil eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>
                    <c:choose>
                        <c:when test="${paketaktif eq 1}">
                            <div class="alert alert-success">
                                Paket aktif hale getirildi.
                            </div>
                        </c:when>
                        <c:when test="${paketaktif eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>
                    <p></p>
                    <table class="table table-hover">
                        <thead>
                            <tr>
                                <th>Paketin Adı
                                    <a href="../orderpacket?condition=title&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacket?condition=title&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Fiyat (TL)
                                    <a href="../orderpacket?condition=price&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacket?condition=price&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Bağış Birimi</th>
                                <th>Son Kullanma Tarihi
                                    <a href="../orderpacket?condition=last_date_used&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacket?condition=last_date_used&order=desc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>İşlemler</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:if test="${packets == null || fn:length(packets) eq 0}">
                                <p>Lütfen yan menüden ilgili kriterlerinizi girip arama yapın.</p>
                            </c:if>
                            <c:forEach var="item" items="${packets}">
                                <tr>
                                    <td>${item.title}</td>
                                    <td align="right">${item.price}</td>
                                    <td>${item.accountInfo.ownerUnit.unitName}
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.lastDateUsed}" /></td>
                                    <td>
                                        <a  href="../packetdetail?packetId=${item.packetId}"
                                            title="Detail"
                                            class="open-deleteCategoryDialog btn btn-primary">
                                            <span class="glyphicon glyphicon-th-list" title="Detay"></span>
                                        </a>
                                        <c:if test="${item.visible eq false}">
                                            <a href="../updateinitpacket?id=${item.packetId}"
                                               title="Düzenle"
                                               class="btn btn-success">
                                                <span class="glyphicon glyphicon-pencil" title="Düzenle"></span>
                                            </a>
                                            <a href="#activePacketDialog"
                                               title="Görünür Yap"
                                               data-id="${item.packetId}"
                                               class="open-activePacketDialog btn btn-info"
                                               data-toggle="modal">
                                                <span class="glyphicon glyphicon-ok" title="Görünür Yap"></span>
                                            </a>
                                            <a  href="#deletePacketDialog"
                                                title="Sil"
                                                data-id="${item.packetId}"
                                                class="open-deletePacketDialog btn btn-danger"
                                                data-toggle="modal">
                                                <span class="glyphicon glyphicon-trash" title="Sil"></span>
                                            </a>
                                        </c:if>
                                    </td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>

        <jsp:include page="../html/footer.html"></jsp:include>
    </body>
</html>
