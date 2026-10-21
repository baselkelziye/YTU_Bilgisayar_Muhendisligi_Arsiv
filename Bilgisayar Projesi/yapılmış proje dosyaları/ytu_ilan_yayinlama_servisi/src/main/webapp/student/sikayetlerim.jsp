<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 11.12.2016
  Time: 22:56
  To change this template use File | Settings | File Templates.
--%>

<html>
    <head>
        <title>Şikayet Ettiğim İlanlar</title>
        <jsp:include page="../html/head.html"></jsp:include>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-detail", function (e) {
                e.preventDefault();
                var _self = $(this);

                var title = _self.data('title');
                var content = _self.data('content');
                var brief = _self.data('brief');
                var company = _self.data('company');
                var publish = _self.data('publish');

                document.getElementById("title1").innerHTML = title;
                document.getElementById("content1").innerHTML = content;
                document.getElementById("publish1").innerHTML = publish;
                document.getElementById("brief1").innerHTML = brief;
                document.getElementById("company1").innerHTML = company;

                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-delete", function (e) {
                e.preventDefault();
                var _self = $(this);
                var code = _self.data('id');
                $("#announcementID").val(code);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
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

        <div class="modal fade" id="delete" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Şikayeti Geri Çek</h4>
                    </div>
                    <div class="modal-body">
                        <p>Şikayeti geri çekmek istediğinize emin misiniz?</p>
                        <br/>
                        <form>
                            <form>
                                <input type="hidden" name="announcementId" id="announcementID">
                                <input formaction="../deletecomplaintfromlist" type="submit" class="btn btn-default" value="Evet">
                                <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                            </form>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Onaylamanız durumunda şikayet veri tabanından silinir.</p>
                        <p>İsterseniz daha sonra tekrar şikayet edebilirsiniz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-2">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Şikayet Ara</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action="../searchmycomplaint">
                                <div class="form-group">
                                    <label>Sonuç</label> <br/>
                                    <input type="radio" name="result" value="Sonuçlanan" >Sonuçlanan<br/>
                                    <input type="radio" name="result" value="Bekleyen" >Bekleyen<br/>
                                    <input type="radio" checked="checked" name="result" value="Tümü" >Tümü<br/>
                                </div>
                                <button type="submit" class="btn btn-success">Ara</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-9">
                    <c:choose>
                        <c:when test="${sikayetgericek eq 1}">
                            <div class="alert alert-success">
                                Şikayetiniz geri alındı.
                            </div>
                        </c:when>
                        <c:when test="${sikayetgericek eq 2}">
                            <div class="alert alert-danger">
                                Şikayetiniz geri alınamadı.
                                Lütfen daha sonra tekrar deneyin.
                            </div>
                        </c:when>
                    </c:choose>

                    <c:if test="${fn:length(complaintList) eq 0}">
                        <p>Gösterilecek şikayet yok</p>
                        <p>Yan panelden seçim yapabilirsiniz.</p>
                    </c:if>
                    <table class="table table-hover">
                        <thead>
                            <tr>
                                <th>İlan Adı
                                    <a href="../mycomplaintorder?condition=title&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../mycomplaintorder?condition=title&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Firma
                                    <a href="../mycomplaintorder?condition=company_name&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../mycomplaintorder?condition=company_name&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Sebep</th>
                                <th>Zaman
                                    <a href="../mycomplaintorder?condition=complaint_time&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../mycomplaintorder?condition=complaint_time&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Sonuç</th>
                                <th>Açıklama</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                        <c:forEach var="item" items="${complaintList}">
                            <tr>
                                <td>${item.announcement.title}</td>
                                <td>${item.announcement.ownerCompany.companyName}</td>
                                <td>
                                    <c:choose>
                                        <c:when test="${fn:length(item.description) < 10}">
                                            ${item.description}
                                        </c:when>
                                        <c:otherwise>
                                            ${fn:substring(item.description, 0, 10)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama:" data-content="${item.description}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </c:otherwise>
                                    </c:choose>
                                </td>
                                <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.complaintTime}"/></td>
                                <td>
                                    <c:if test="${item.result eq null}">
                                        <i>Sonuçlanmadı</i>
                                    </c:if>
                                    ${item.result}
                                </td>
                                <td>
                                    <c:choose>
                                        <c:when test="${fn:length(item.resultReply) < 10}">
                                            ${item.resultReply}
                                        </c:when>
                                        <c:otherwise>
                                            ${fn:substring(item.resultReply, 0, 10)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama:" data-content="${item.resultReply}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </c:otherwise>
                                    </c:choose>
                                </td>
                                <td>
                                    <a  href="#detail"
                                        title="İlan Detay"
                                        data-toggle="modal"
                                        data-title="${item.announcement.title}"
                                        data-content="${item.announcement.content}"
                                        data-brief="${item.announcement.state.title}"
                                        data-company="${item.announcement.ownerCompany.companyName}"
                                        data-publish="${item.announcement.publishDate}"
                                        class="open-detail btn btn-info">
                                        <span class="glyphicon glyphicon-th"></span>
                                    </a>
                                    <c:if test="${item.result eq null}">
                                        <a  href="#delete"
                                            title="Şikayeti Geri Çek"
                                            data-toggle="modal"
                                            data-id="${item.announcement.id}"
                                            class="open-delete btn btn-danger">
                                            <span class="glyphicon glyphicon-remove"></span>
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
    </body>
</html>
