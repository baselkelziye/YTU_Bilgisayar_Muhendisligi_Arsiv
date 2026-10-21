<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 18.12.2016
  Time: 17:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>Aktif ve Cezalı İlanlar</title>
        <jsp:include page="html/head.html"/>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-activeDetail", function (e) {
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

            $(document).on("click", ".open-suspendedDetail", function (e) {
                e.preventDefault();
                var _self = $(this);

                var title = _self.data('title');
                var content = _self.data('content');
                var brief = _self.data('brief');
                var company = _self.data('company');
                var publish = _self.data('publish');
                var description = _self.data('description');

                document.getElementById("title2").innerHTML = title;
                document.getElementById("content2").innerHTML = content;
                document.getElementById("publish2").innerHTML = publish;
                document.getElementById("brief2").innerHTML = brief;
                document.getElementById("company2").innerHTML = company;
                document.getElementById("description2").innerHTML = description;

                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="activeDetail" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
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

        <div class="modal fade" id="suspendedDetail" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <h4>İlan Detayları</h4>

                        <p><b>Ceza Sebebi</b></p>
                        <p id="description2"></p>

                        <p><b>Başlık</b></p>
                        <p id="title2"></p>

                        <p><b>Kısa Açıklama</b></p>
                        <p id="brief2"></p>

                        <p><b>İçerik</b></p>
                        <p id="content2"></p>

                        <p><b>Şirket Adı</b></p>
                        <p id="company2"></p>

                        <p><b>Yayınlanma Tarihi</b></p>
                        <p id="publish2"></p>

                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-5">
                    <h4><b>Aktif İlanlar</b></h4>
                    <p>Sırala</p>
                    <a href="#">Şirket Adına Göre</a><br/>
                    <a href="#">Yayınlanma Tarihine Göre</a>
                    <table class="table table-stripped">
                        <thead>
                            <tr>
                                <th>İlan Başlığı</th>
                                <th>Şirket</th>
                                <th>Yayımlanma Tarihi</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${activeAnnList}">
                                <tr>
                                    <td>${item.title}</td>
                                    <td>${item.ownerCompany.companyName}</td>
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.publishDate}"/></td>
                                    <td>
                                        <a href="#activeDetail"
                                           data-toggle="modal"
                                           data-title="${item.title}"
                                           data-content="${item.content}"
                                           data-brief="${item.state.title}"
                                           data-company="${item.ownerCompany.companyName}"
                                           data-publish="${item.publishDate}"
                                           class="open-activeDetail btn btn-info"
                                           title="Detay">
                                            <span class="glyphicon glyphicon-th"></span>
                                        </a>
                                        <a  href="#"
                                            class="btn btn-danger"
                                            title="Yayından Kaldır Kaldır">
                                            <span class="glyphicon glyphicon-remove"></span>
                                        </a>
                                    </td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
                <div class="col-md-5">
                    <h4><b>Cezalı İlanlar</b></h4>
                    <p>Sırala</p>
                    <a href="#">Şirket Adına Göre</a><br/>
                    <a href="#">Ceza Tarihine Göre</a>
                    <table class="table table-stripped">
                        <thead>
                            <tr>
                                <th>İlan Başlığı</th>
                                <th>Şirket</th>
                                <th>Şikayet Sayısı</th>
                                <th>Ceza Tarihi</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${suspendedAnnList}">
                                <tr>
                                    <td>${item.title}</td>
                                    <td>${item.ownerCompany.companyName}</td>
                                    <td>${fn: length(item.complaintList)}</td>
                                    <td>${item.complaintList[0].resultTime}</td>
                                    <td>
                                        <a  href="#suspendedDetail"
                                            data-toggle="modal"
                                            data-description="${item.complaintList[0].resultReply}"
                                            data-title="${item.title}"
                                            data-content="${item.content}"
                                            data-brief="${item.state.title}"
                                            data-company="${item.ownerCompany.companyName}"
                                            data-publish="${item.publishDate}"
                                            class="open-suspendedDetail btn btn-info"
                                            title="Detay">
                                            <span class="glyphicon glyphicon-th"></span>
                                        </a>
                                        <a  href="#"
                                            class="btn btn-success"
                                            title="Cezayı Kaldır">
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
