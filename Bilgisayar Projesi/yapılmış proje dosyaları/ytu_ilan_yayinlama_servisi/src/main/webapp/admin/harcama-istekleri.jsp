<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 06.12.2016
  Time: 01:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<html>
    <head>
        <title>Harcama İstekleri</title>
        <jsp:include page="html/head.html"/>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    </head>
    <body>

        <script>
            $(document).on("click", ".download-file", function (e) {
                e.preventDefault();
                var _self = $(this);
                var idPath = _self.data('path');
                var idType = _self.data('type');
                $("#path").val(idPath);
                $("#type").val(idType);
                $(_self.attr('href')).modal('show');
            });

            function nonVisible() {
                $('#downloadFile').modal('hide');
            }

            $(document).on("click", ".open-detail", function (e) {
                e.preventDefault();
                var _self = $(this);

                var title = _self.data('title');
                var content = _self.data('content');
                var sentDateTime = _self.data('se');
                var updatedDateTime = _self.data('up');
                var dauUser = _self.data('da');
                var dau = _self.data('dau');
                var state = _self.data('state');
                var answer = _self.data('answer');
                var amount = _self.data('amount');

                document.getElementById("title1").innerHTML = title;
                document.getElementById("amount1").innerHTML = amount;
                document.getElementById("content1").innerHTML = content;
                document.getElementById("updatedDateTime1").innerHTML = updatedDateTime;
                document.getElementById("dauUser1").innerHTML = dauUser;
                document.getElementById("dau1").innerHTML = dau;
                document.getElementById("state1").innerHTML = state;
                document.getElementById("answer1").innerHTML = answer;
                document.getElementById("sentDateTime1").innerHTML = sentDateTime;

                $(_self.attr('href')).modal('show');
            });
        </script>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>

        <div class="modal fade" id="downloadFile" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" onclick="nonVisible()">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Dosyayı İndir</p>
                        <form>
                            <input type="hidden" name="fileName" id="path">
                            <input type="hidden" name="fileType" id="type">
                            <input formaction="../pdfviewer" type="submit" class="btn btn-default" value="Evet" onA>
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="detail" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <h4>İstek Detayları</h4>

                        <p><b>Durum</b></p>
                        <p id="state1"></p>

                        <p><b>Başlık</b></p>
                        <p id="title1"></p>

                        <p><b>Mesajınız</b></p>
                        <p id="content1"></p>

                        <p><b>İstek Gönderme Tarihi</b></p>
                        <p id="sentDateTime1"></p>

                        <p><b>Miktar</b></p>
                        <p id="amount1"></p>

                        <p><b>BKB</b></p>
                        <p id="dau1"></p>

                        <p><b>Kullanıcı</b></p>
                        <p id="dauUser1"></p>

                        <p><b>Cevap</b></p>
                        <p id="answer1"></p>

                        <p><b>Cevaplanma Tarihi</b></p>
                        <p id="updatedDateTime1"></p>

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
                            <p>Arama Seçenekleri</p>
                        </div>
                        <div class="panel-body">
                            <form action="../spendingrequestdau" method="post">
                                <div class="form-group">
                                    <label for="state">Durum</label>
                                    <select name="state" id="state" class="form-control">
                                        <c:forEach var="item" items="${stateList}">
                                            <c:choose>
                                                <c:when test="${item.id eq -1}">
                                                    <option selected value="${item.id}">
                                                        <c:out value="${item.title}"/>
                                                    </option>
                                                </c:when>
                                                <c:otherwise>
                                                    <option value="${item.id}">
                                                        <c:out value="${item.title}"/>
                                                    </option>
                                                </c:otherwise>
                                            </c:choose>
                                        </c:forEach>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="dau">Birim</label>
                                    <select name="department" id="dau" class="form-control">
                                        <c:forEach var="item" items="${dauList}">
                                            <c:choose>
                                                <c:when test="${item.unitName eq 'Tüm Birimler'}">
                                                    <option selected value="${item.unitName}">
                                                        <c:out value="${item.unitName}"/>
                                                    </option>
                                                </c:when>
                                                <c:otherwise>
                                                    <option value="${item.unitName}">
                                                        <c:out value="${item.unitName}"/>
                                                    </option>
                                                </c:otherwise>
                                            </c:choose>
                                        </c:forEach>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Ara</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-8">
                    <table class="table table-hover">
                        <thead>
                        <tr>
                            <th>Başlık</th>
                            <th>Cevap</th>
                            <th>Cevap Tarihi
                                <a href="../spendingrequestorder?condition=updated_date_time&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../spendingrequestorder?condition=updated_date_time&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>Kullanıcı
                                <a href="../spendingrequestorder?condition=updater&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../spendingrequestorder?condition=updater&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>İşlem</th>
                        </tr>
                        </thead>
                        <tbody>
                        <c:if test="${fn:length(srList) eq 0}">
                            <p>Lütfen yan panelden seçim yapınız.</p>
                        </c:if>
                        <c:forEach var="item" items="${srList}">
                            <tr>
                                <td>
                                    <c:choose>
                                        <c:when test="${fn:length(item.title) < 20}">
                                            ${item.title}
                                        </c:when>
                                        <c:otherwise>
                                            ${fn:substring(item.title, 0, 20)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama:" data-content="${item.title}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </c:otherwise>
                                    </c:choose>
                                </td>
                                <td>
                                    <c:choose>
                                        <c:when test="${item.answerFromUpdater ne null}">
                                            ${fn:substring(item.answerFromUpdater, 0, 20)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama:" data-content="${item.answerFromUpdater}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </c:when>
                                        <c:otherwise>
                                            <i>Sonuçlanmadı</i>
                                        </c:otherwise>
                                    </c:choose>
                                </td>
                                <td><fmt:formatDate type="date" value="${item.updatedDateTime}"/></td>
                                <td>${item.dauUser.userName}</td>
                                <td width="15%">
                                    <a href="#detail"
                                       class="open-detail"
                                       data-toggle="modal"
                                       data-title="${item.title}"
                                       data-content="${item.content}"
                                       data-state="${item.state.title}"
                                       data-da="${item.dauUser.userName}"
                                       data-dau="${item.dauUser.dau.unitName}"
                                       data-answer="${item.answerFromUpdater}"
                                       data-amount="${item.amount}"
                                       data-se="${item.sentDateTime}"
                                       data-up="${item.updatedDateTime}"
                                       title="Detay Gör">
                                        <span class="glyphicon glyphicon-eye-open"></span>
                                    </a>
                                    <c:if test="${item.imagePath ne null}">
                                        <a href="#downloadFile"
                                           title="Görüntü İndir"
                                           data-path="${item.imagePath}"
                                           data-type="image"
                                           class="download-file"
                                           data-toggle="modal">
                                            <span class="glyphicon glyphicon-camera"></span>
                                        </a>
                                    </c:if>
                                    <c:if test="${item.pdfPath ne null}">
                                        <a href="#downloadFile"
                                           title="Pdf İndir"
                                           data-type="pdf"
                                           data-path="${item.pdfPath}"
                                           class="download-file"
                                           data-toggle="modal"><span class="glyphicon glyphicon-paperclip"></span>
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
        <jsp:include page="html/footer.html"/>
    </body>
</html>
