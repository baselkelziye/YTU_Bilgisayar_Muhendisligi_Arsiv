<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 21.01.2017
  Time: 12:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>Reddedilen Şikayetler</title>

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

            $(document).on("click", ".open-complaintList", function (e) {
                e.preventDefault();
                var _self = $(this);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-punish", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#annid").val(id);
                $(_self.attr('href')).modal('show');
            });
        </script>
    </head>
    <body>
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

        <div class="modal fade" id="punish" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p><b>İlanı yayından kaldır!</b></p>
                        <form>
                            <input type="hidden" name="id" id="annid">
                            <div class="form-group">
                                <label>Açıklama</label><br/>
                                <textarea rows="3" class="form-control" name="description"></textarea>
                            </div>

                            <input formaction="../repunishbyadmin" type="submit" class="btn btn-default" value="Yayından Kaldır">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Bu ilana artık Onaylanan sekmesinden erişebilirsiniz.</p>
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
                    <ul class="nav nav-tabs">
                        <li><a href="../complaintlisttoadmin">Yeni</a></li>
                        <li><a href="../acceptedcomplaintlist">Onaylanan</a></li>
                        <li class="active"><a style="background-color:#b9def0" href="../rejectedcomplaintlist">Reddedilen</a></li>
                        <li><a href="../complaintreporttoadmin">Rapor Al</a></li>
                    </ul>
                    <br/>

                    <c:choose>
                        <c:when test="${yayindankaldir eq 1}">
                            <div class="alert alert-success">
                                İlan yayından kaldırıldı.
                            </div>
                        </c:when>
                        <c:when test="${yayindankaldir eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>
                    <table class="table table-stripped">
                        <thead>
                            <tr>
                                <th>İlan Adı</th>
                                <th>Yayın Tarihi</th>
                                <th>Şirket</th>
                                <th>Şikayet Sayısı</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:if test="${fn:length(retsikayet) eq 0}">
                                <tr><td><i>Reddedilen şikayet yok.</i></td></tr>
                            </c:if>
                            <c:forEach var="item" items="${retsikayet}">
                                <tr>
                                    <td>${item.title}</td>
                                    <td><fmt:formatDate pattern="dd-MM-yyy" value="${item.publishDate}"/></td>
                                    <td>${item.ownerCompany.companyName}</td>
                                    <td align="right">${fn:length(item.complaintList)}</td>
                                    <td>
                                        <a  href="#detail"
                                            title="Detay"
                                            data-toggle="modal"
                                            data-title="${item.title}"
                                            data-content="${item.content}"
                                            data-brief="${item.brief}"
                                            data-company="${item.ownerCompany.companyName}"
                                            data-publish="${item.publishDate}"
                                            class="open-detail btn btn-success">
                                            <span class="glyphicon glyphicon-th-large"></span>
                                        </a>
                                        <a  href="#punish"
                                            title="İlanı yayından kaldır"
                                            data-toggle="modal"
                                            data-id="${item.id}"
                                            class="open-punish btn btn-danger">
                                            <span class="glyphicon glyphicon-remove"></span>
                                        </a>
                                    </td>
                                </tr>
                                <tr>
                                    <td colspan="5">
                                        <button type="button" class="btn btn-info" data-toggle="collapse" data-target="#${item.id}">Şikayet Mesajları</button>
                                        <div id="${item.id}" class="collapse out">
                                            <c:forEach var="item2" items="${item.complaintList}">
                                                <b>Kullanıcı:</b>${item2.student.userName}<br/>
                                                <b>Mesaj:</b>${item2.description}<br/><br/>
                                            </c:forEach>
                                        </div>
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
