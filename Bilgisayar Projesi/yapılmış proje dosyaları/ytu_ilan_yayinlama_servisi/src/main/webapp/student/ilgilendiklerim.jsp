<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 07.01.2017
  Time: 13:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"></jsp:include>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.12.1/css/bootstrap-select.min.css">
        <script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.12.1/js/bootstrap-select.min.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/bootstrap-select/1.12.1/js/i18n/defaults-*.min.js"></script>
        <title>İlgilendiklerim</title>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-ekleDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-duzenleDialog", function (e) {
                e.preventDefault();
                var _self = $(this);

                var name1 = _self.data('name');
                var category = _self.data('category');
                var language = _self.data('language');
                var type = _self.data('type');
                var keywords = _self.data('keywords');

                $("#name2").val(name1);
                $("#oldName").val(name1);
                $("#keywords2").val(keywords);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-deleteCriteria", function (e) {
                e.preventDefault();
                var _self = $(this);
                var name = _self.data('name');
                $("#name").val(name);
                $(_self.attr('href')).modal('show');
            });
        </script>
        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>

        <div class="modal fade" id="deleteCriteria" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" onclick="nonVisible()">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Kriterleri Sil!</p>
                        <form>
                            <input type="hidden" name="name" id="name">
                            <input formaction="../deleteinterests" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="ekleDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Yeni Kriter Ekleyin</h4>
                    </div>
                    <div class="modal-body">
                        <p>Lütfen formu ilgilendiğiniz şekilde doldurun</p>
                        <form method="post" action="../addinterests">
                            <div class="form-group">
                                <div class="form-group">
                                    <label for="name1">Kriter Adı</label>
                                    <input type="text" name="name" id="name1" class="form-control" maxlength="20" minlength="1">
                                </div>
                                <label>İlan Kategorisi</label>
                                <select data-live-search="true" name="category" class="selectpicker form-control">
                                    <c:forEach var="item" items="${categoryList}">
                                        <c:if test="${item.id ne 0 }">
                                            <c:if test="${item.parentCategory eq 0}">
                                                <option selected value="${item.id}">
                                                    <b><c:out value="${item.categoryName}"/></b>
                                                </option>
                                                <c:forEach var="childItem" items="${item.children}">
                                                    <option value="${childItem.id}">
                                                        <c:out value="----${childItem.categoryName}"/>
                                                    </option>
                                                </c:forEach>
                                            </c:if>
                                        </c:if>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>İlan Tipi</label>
                                <select name="type" class="form-control">
                                    <c:forEach var="item" items="${annType}">
                                        <option value="${item.id}">
                                            <c:out value="${item.title}"/>
                                        </option>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>İlanın Dili</label>
                                <select name="language" class="form-control" id="language">
                                    <option value="alllanguages">Tüm Diller</option>
                                    <option value="türkçe">Türkçe</option>
                                    <option value="ingilizce">İngilizce</option>
                                </select>
                            </div>
                            <div class="form-group">
                                <label for="keyword">Anahtar Kelimeler</label>
                                <h5>Kelimeler arasında virgül bırakın.(Ör: java,hibernate,css)</h5>
                                <input type="text" name="keywords" placeholder="Anahtar Kelimeler" class="form-control" id="keyword">

                            </div>

                            <button type="submit" class="btn btn-success">Kaydet</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Kayıtlı kriterlerinizi istediğiniz zaman silebilir-düzenleyebilirsiniz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="duzenleDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel4" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Kriterlerinizi Düzenleyin</h4>
                    </div>
                    <div class="modal-body">
                        <p>Lütfen istediğiniz şekilde düzenleyin</p>
                        <form method="post" action="../updateinterests">
                            <div class="form-group">
                                <div class="form-group">
                                    <label for="name1">Kriter Adı</label>
                                    <input type="text" name="name" id="name2" class="form-control" maxlength="20" minlength="1">
                                </div>
                                <label>İlan Kategorisi</label>
                                <select data-live-search="true" name="category" class="selectpicker form-control">
                                    <c:forEach var="item" items="${categoryList}">
                                        <c:if test="${item.id ne 0 }">
                                            <c:if test="${item.parentCategory eq 0}">
                                                <option selected value="${item.id}">
                                                    <b><c:out value="${item.categoryName}"/></b>
                                                </option>
                                                <c:forEach var="childItem" items="${item.children}">
                                                    <option value="${childItem.id}">
                                                        <c:out value="----${childItem.categoryName}"/>
                                                    </option>
                                                </c:forEach>
                                            </c:if>
                                        </c:if>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>İlan Tipi</label>
                                <select name="type" class="form-control">
                                    <c:forEach var="item" items="${annType}">
                                        <option value="${item.id}">
                                            <c:out value="${item.title}"/>
                                        </option>
                                    </c:forEach>
                                </select>
                            </div>
                            <div class="form-group">
                                <label>İlanın Dili</label>
                                <select name="language" class="form-control" id="language2">
                                    <option value="alllanguages">Tüm Diller</option>
                                    <option value="türkçe">Türkçe</option>
                                    <option value="ingilizce">İngilizce</option>
                                </select>
                            </div>
                            <div class="form-group">
                                <label for="keyword">Anahtar Kelimeler</label>
                                <h5>Kelimeler arasında virgül bırakın.(Ör: java,hibernate,css)</h5>
                                <input type="text" name="keywords" placeholder="Anahtar Kelimeler" class="form-control" id="keywords2">
                            </div>

                            <input type="hidden" name="oldName" id="oldName">
                            <button type="submit" class="btn btn-success">Güncelle</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Kayıtlı kriterlerinizi istediğiniz zaman silebilir-düzenleyebilirsiniz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-1">
                    <a href="#ekleDialog" class="open-ekleDialog button btn btn-success"><span class="glyphicon glyphicon-plus"></span> Ekle</a>
                </div>
                <div class="col-md-3">
                    <c:choose>
                        <c:when test="${eklendi eq 1}">
                            <div class="alert alert-success">
                                Kayıt işlemi başarılı.
                            </div>
                        </c:when>
                        <c:when test="${eklendi eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                        <c:when test="${silindi eq 1}">
                            <div class="alert alert-success">
                                Silme işlemi başarılı.
                            </div>
                        </c:when>
                        <c:when test="${silindi eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                        <c:when test="${guncellendi eq 1}">
                            <div class="alert alert-success">
                                Güncelleme işlemi başarılı.
                            </div>
                        </c:when>
                        <c:when test="${guncellendi eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>
                </div>
            </div>
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-8">
                    <table class="table table-hovered">
                        <thead>
                            <tr>
                                <th>Adı
                                    <a href="../interestsorder?condition=name&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../interestsorder?condition=name&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Kategori
                                    <a href="../interestsorder?condition=category&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../interestsorder?condition=category&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>İlan Tip
                                    <a href="../interestsorder?condition=ann_type&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../interestsorder?condition=ann_type&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Dil
                                    <a href="../interestsorder?condition=language&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../interestsorder?condition=language&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Anahtar Kelimeler</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${interests}">
                                <tr>
                                    <td>${item.name}</td>
                                    <td>${item.category.categoryName}</td>
                                    <td>${item.type.title}</td>
                                    <td>
                                        <c:choose>
                                            <c:when test="${item.language eq 'alllanguages'}">
                                                Tüm Diller
                                            </c:when>
                                            <c:otherwise>
                                                ${item.language}
                                            </c:otherwise>
                                        </c:choose>
                                        </td>
                                    <td>
                                        <c:choose>
                                            <c:when test="${fn:length(item.keywords) < 17}">
                                                ${fn:replace(item.keywords, ",", " ")}
                                            </c:when>
                                            <c:otherwise>
                                                ${fn:substring(fn:replace(item.keywords, ",", " "), 0, 17)}...
                                                <a href="#" data-toggle="popover" data-placement="left"
                                                   title="Anahtar Kelimeler:" data-content="${fn:replace(item.keywords, ",", " ")}">
                                                    <span class="glyphicon glyphicon-info-sign "></span>
                                                </a>
                                            </c:otherwise>
                                        </c:choose>
                                    </td>
                                    <td>
                                        <a  title="Arama Yap"
                                            class="btn btn-primary"
                                            href="../searchannouncement?category=${item.category.id}&type=${item.type.id}&language=${item.language}&keywords=${item.keywords}">
                                            <span class="glyphicon glyphicon-search"></span>
                                        </a>
                                        <a  title="Düzenle"
                                            data-name="${item.name}"
                                            data-category="${item.category.categoryName}"
                                            data-type="${item.type.title}"
                                            data-language="${item.language}"
                                            data-keywords="${item.keywords}"
                                            class="open-duzenleDialog btn btn-success"
                                            href="#duzenleDialog">
                                            <span class="glyphicon glyphicon-pencil"></span>
                                        </a>
                                        <a  title="Sil"
                                            class="open-deleteCriteria btn btn-danger"
                                            data-name="${item.name}"
                                            href="#deleteCriteria">
                                            <span class="glyphicon glyphicon-trash"></span>
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
