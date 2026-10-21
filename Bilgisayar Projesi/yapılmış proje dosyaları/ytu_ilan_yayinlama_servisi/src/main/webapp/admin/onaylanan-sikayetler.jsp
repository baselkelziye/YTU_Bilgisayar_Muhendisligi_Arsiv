<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 21.01.2017
  Time: 12:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>Onaylanan Şikayetler</title>
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

            $(document).on("click", ".open-complaintList", function (e) {
                e.preventDefault();
                var _self = $(this);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-republish", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#annid").val(id);
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

        <div class="modal fade" id="republish" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p><b>İlanı yeniden yayına al</b></p>
                        <form>
                            <input type="hidden" name="id" id="annid">
                            <div class="form-group">
                                <label>Açıklama</label><br/>
                                <textarea rows="3" class="form-control" name="description"></textarea>
                            </div>

                            <input formaction="../republishbyadmin" type="submit" class="btn btn-default" value="Yayına Al">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Yayın süresine kayıp günler ilave edilir.</p>
                        <p>Bu ilana artık Reddedilen sekmesinden erişebilirsiniz.</p>
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
                        <li class="active"><a style="background-color:#b9def0" href="../acceptedcomplaintlist">Onaylanan</a></li>
                        <li><a href="../rejectedcomplaintlist">Reddedilen</a></li>
                        <li><a href="../complaintreporttoadmin">Rapor Al</a></li>
                    </ul>
                    <br>

                    <c:choose>
                        <c:when test="${yenidenyayin eq 1}">
                            <div class="alert alert-success">
                                İlan yeniden yayına alındı.
                                İlana Reddedilen sekmesinden erişebilirsiniz.
                                Son yayın tarihine eklenen gün sayısı: ${iadegun}
                            </div>
                        </c:when>
                        <c:when test="${yenidenyayin eq 2}">
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
                        <c:if test="${fn:length(cezaliilanlar) eq 0}">
                            <tr><td><i>Cezalı ilan yok.</i></td></tr>
                        </c:if>
                        <c:forEach var="item" items="${cezaliilanlar}">
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
                                        class="open-detail btn btn-info">
                                        <span class="glyphicon glyphicon-th-large"></span>
                                    </a>
                                    <a  href="#complaintList"
                                        title="Şikayet Mesajları"
                                        data-toggle="modal"
                                        class="open-complaintList btn btn-success">
                                        <span class="glyphicon glyphicon-list-alt"></span>
                                    </a>

                                    <a  href="#republish"
                                        title="İlanı yeniden yayına al"
                                        data-toggle="modal"
                                        data-id="${item.id}"
                                        class="open-republish btn btn-primary">
                                        <span class="glyphicon glyphicon-retweet"></span>
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
