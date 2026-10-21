<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 12.12.2016
  Time: 17:06
  To change this template use File | Settings | File Templates.
--%>

<html>
    <head>
        <title>Şikayet Edilen İlanlar</title>
        <jsp:include page="html/head.html"/>
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
                var category = _self.data('category');
                var type = _self.data('type');

                document.getElementById("title1").innerHTML = title;
                document.getElementById("content1").innerHTML = content;
                document.getElementById("publish1").innerHTML = publish;
                document.getElementById("brief1").innerHTML = brief;
                document.getElementById("company1").innerHTML = company;
                document.getElementById("category1").innerHTML = category;
                document.getElementById("type1").innerHTML = type;


                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".true-complaint", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');

                $("#annid").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".false-complaint", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');

                $("#annid2").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-complaintList", function (e) {
                e.preventDefault();
                var _self = $(this);
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

                        <p><b>Kategori</b></p>
                        <p id="category1"></p>

                        <p><b>Tip</b></p>
                        <p id="type1"></p>

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

        <div class="modal fade" id="trueComplaint" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Şikayetleri Onayla!</h4>
                    </div>
                    <div class="modal-body">
                        <h4>İlanı Yayımdan Kaldır</h4>
                        <p>Lütfen ilanın neden yayımdan kaldırıldığına dair açıklama giriniz</p>
                        <form method="post" action="../acceptcomplaint">
                            <textarea cols="40" rows="10" name="resultReply" class="form-control"></textarea>
                            <br/>
                            <button type="submit" class="btn btn-default"class="form-control">Yayımdan Kaldır</button>
                            <input type="hidden" id="annid" name="annID">
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Yazmış olduğunuz açıklama şirkete iletilecektir.</p>
                        <p>Cezalı ilanların düzenlenip tekrar yayına alınması mümkün değildir.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="falseComplaint" tabindex="-1" role="dialog" aria-labelledby="myModalLabel4" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Şikayetleri Reddet!</h4>
                    </div>
                    <div class="modal-body">
                        <h4>Şikayetlerin yanlış olduğuna kanaat getirdiniz</h4>
                        <p>Lütfen bu düşüncenizin nedenini açıklayın.</p>
                        <form method="post" action="../rejectcomplaint">
                            <textarea cols="40" rows="10" name="resultReply" class="form-control"></textarea>
                            <br/>
                            <button type="submit" class="btn btn-default"class="form-control">Gönder</button>
                            <input type="hidden" id="annid2" name="annID">
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Yazmış olduğunuz açıklama şikayet eden öğrencilere iletilecektir.</p>
                        <p>İlanı şikayet eden öğrencilere ceza puanı eklenecektir.</p>
                        <p>İlan tekrar şikayet edilemez durumda olacaktır. </p>
                        <p>Kararınızı değiştirirseniz ilanlar sayfasından ilanı yayından kaldırabilirsiniz.</p>
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
                        <li class="active"><a href="../complaintlisttoadmin"" style="background-color:#b9def0">Yeni</a></li>
                        <li><a href="../acceptedcomplaintlist">Onaylanan</a></li>
                        <li><a href="../rejectedcomplaintlist">Reddedilen</a></li>
                        <li><a href="../complaintreporttoadmin">Rapor Al</a></li>
                    </ul>
                    <br>
                    <c:choose>
                        <c:when test="${ceza eq 1}">
                            <div class="alert alert-success">
                                İlan yayından kaldırıldı.
                            </div>
                        </c:when>
                        <c:when test="${ceza eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                                Lütfen daha sonra tekrar deneyiniz.
                            </div>
                        </c:when>
                        <c:when test="${ret eq 1}">
                            <div class="alert alert-success">
                                Şikayetler reddedildi.
                            </div>
                        </c:when>
                        <c:when test="${ret eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                                Lütfen daha sonra tekrar deneyiniz.
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
                            <c:if test="${fn:length(sikayetilan) eq 0}">
                                <tr><td><i>Yeni şikayet yok.</i></td></tr>
                            </c:if>
                            <c:forEach var="item" items="${sikayetilan}">
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
                                            data-category="${item.category.categoryName}"
                                            data-type="${item.announcementType.title}"
                                            data-company="${item.ownerCompany.companyName}"
                                            data-publish="${item.publishDate}"
                                            class="open-detail btn btn-info">
                                            <span class="glyphicon glyphicon-th-large"></span>
                                        </a>
                                        <a  href="#trueComplaint"
                                            title="Şikayetler Doğru"
                                            data-toggle="modal"
                                            data-id="${item.id}"
                                            class="true-complaint btn btn-primary">
                                            <span class="glyphicon glyphicon-ok"></span>
                                        </a>
                                        <a  href="#falseComplaint"
                                            title="Şikayetler Asılsız"
                                            data-toggle="modal"
                                            data-id="${item.id}"
                                            class="false-complaint btn btn-danger">
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
        <jsp:include page="html/footer.html"/>
    </body>
</html>
