<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 28.01.2017
  Time: 21:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Onay Bekleyen Şirketler</title>
        <jsp:include page="html/head.html"/>

        <script>
            $(document).on("click", ".open-reject", function (e) {
                e.preventDefault();
                var _self = $(this);
                var username = _self.data('username');

                $("#username").val(username);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-approve", function (e) {
                e.preventDefault();
                var _self = $(this);
                var username = _self.data('username');

                $("#username2").val(username);
                $(_self.attr('href')).modal('show');
            });
        </script>
    </head>
    <body>

        <div class="modal fade" id="reject" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Kayıt isteğini reddet</p>
                        <form>
                            <input type="hidden" name="username" id="username">
                            <input formaction="../rejectcompany" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Veri tabanındaki ilgili kısımlar silinecektir.</p>
                        <p>Bu işlem geri alınamaz</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="approve" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Kayıt isteğini onayla</p>
                        <form>
                            <input type="hidden" name="username" id="username2">
                            <input formaction="../approvecompanyservlet" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Kullanıcının hesaba erişimi aktif olacaktır.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-4">
                    <c:choose>
                        <c:when test="${istek eq 1}">
                            <div class="alert alert-success">
                                İstek ret edildi.
                            </div>
                        </c:when>
                        <c:when test="${istek eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                        <c:when test="${istek eq 3}">
                            <div class="alert alert-success">
                                İstek onaylandı.
                            </div>
                        </c:when>
                    </c:choose>
                </div>
            </div>
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-11">
                    <table class="table table-hover">
                        <thead>
                            <th>Şirket Adı</th>
                            <th>Yetkili Adı</th>
                            <th>Telefon</th>
                            <th>Mail</th>
                            <th>Mersis</th>
                            <th>KEP</th>
                            <th>İşlem</th>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${companyList}">
                                <tr>
                                    <td>${item.companyName}</td>
                                    <td>${item.name} ${item.surname}</td>
                                    <td>${item.contactTel}</td>
                                    <td>${item.contactMail}</td>
                                    <td>${item.mersis}</td>
                                    <td>${item.kep}</td>
                                    <td>
                                        <a  href="#approve"
                                            title="Onayla"
                                            data-toggle="modal"
                                            data-username="${item.userName}"
                                            class="open-approve btn btn-success">
                                            <span class="glyphicon glyphicon-ok"></span>
                                        </a>
                                        <a  href="#reject"
                                            title="Reddet"
                                            data-toggle="modal"
                                            data-username="${item.userName}"
                                            class="open-reject btn btn-danger">
                                            <span class="glyphicon glyphicon-remove"></span>
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
