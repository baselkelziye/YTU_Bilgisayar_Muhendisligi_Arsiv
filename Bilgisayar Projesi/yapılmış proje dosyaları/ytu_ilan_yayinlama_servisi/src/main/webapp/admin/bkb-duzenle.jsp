<%-- 
    Document   : displaydau
    Created on : 01.May.2016, 16:11:35
    Author     : must
--%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <title>BKB Listesi</title>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-deleteDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var unitID = _self.data('unit');

                $("#unit").val(unitID);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="deleteModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">BKB Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="unitName" id="unit">
                            <input formaction="../deletedau" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Üzerine paket tanımlanmış birimler silinemez.</p>
                        <p>Muhasebe kaydı olan birimler silinemez.</p>
                        <p>Bir BKB silinirse ona bağlı kullanıcılar da silinir.</p>
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
                        <c:when test="${bkbsil eq 1}">
                            <div class="alert alert-success">
                                BKB silindi.
                            </div>
                        </c:when>
                        <c:when test="${bkbsil eq 2}">
                            <div class="alert alert-danger">
                                BKB silinemedi! Lütfen muhasabe kayıtlarını ve tanımlanmış paketleri inceleyin.
                            </div>
                        </c:when>
                    </c:choose>
                     <h3><b>Tanımlı Bağış Kabul Edebilecek Birimler</b></h3>
                     <table class="table table-hovered">
                        <thead>
                            <tr>
                                <th>Birim Adı</th>
                                <th>Bakiye</th>
                                <th>Oluşturulma Tarihi</th>
                                <th>Kullanıcı Sayısı</th>
                                <th>Hesap Sayısı</th>
                                <th>İşlemler</th>
                            </tr>
                        </thead>
                        <tbody>

                            <c:forEach var="item" items="${dauList}">
                                <tr>
                                    <td>${item.unitName}</td>
                                    <td align="right">${item.balance}</td>
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.createdDate}"/></td>
                                    <td align="right">${fn:length(item.dauUser)}</td>
                                    <td align="right">${fn:length(item.account)}</td>
                                    <td>
                                        <form action="../bkbdetail">
                                            <input type="hidden" name="dauName" value="${item.unitName}">
                                            <button type="submit" class="btn btn-success">
                                               <span class="glyphicon glyphicon-eye-open" ></span>
                                            </button>
                                            <a
                                                data-toggle="modal"
                                                href="#deleteModal"
                                                class="open-deleteDialog"
                                                data-unit="${item.unitName}"
                                                title="Sil">
                                                <span class="glyphicon glyphicon-trash btn btn-danger"></span>
                                            </a>
                                        </form>

                                    </td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>

                    <a href="../newdonationacceptunit" class="btn btn-info">Yeni Birim Ekle</a>
                </div>
            </div>
        </div>

        <jsp:include page="html/footer.html"/>
    </body>
</html>