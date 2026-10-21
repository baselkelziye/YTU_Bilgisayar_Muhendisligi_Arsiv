<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib tagdir="/WEB-INF/tags"  prefix="template" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
    <html>
        <head>
            <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
            <jsp:include page="html/head.html"/>
            <title>Kategori İşlemleri</title>
        </head>
    <body>
        <script>
            $(document).on("click", ".open-deleteCategoryDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#cid").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-editCategoryDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var name = _self.data('name');
                var id = _self.data('id');
                $("#cid2").val(id);
                $("#categoryName").val(name);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="deleteCategoryDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Kategori Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="id" id="cid">
                            <input formaction="../deletecategory" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Kullanımda olan kategoriler silinemez. </p>
                        <p>Alt kategorileri sahip olan kategoriler silinemez. </p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="editCategoryDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Kategori Düzenle!</h4>
                    </div>
                    <div class="modal-body">
                        <p>İsmi Düzenleyin</p>
                        <form>
                            <input type="hidden" name="id" id="cid2">
                            <div class="form-group">
                                <label for="categoryName">Yeni İsim:</label>
                                <input type="text" name="categoryName" id="categoryName" class="form-control"/>
                            </div>
                            <input formaction="../updatecategory" type="submit" class="btn btn-success" value="Değiştir">
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Sistemde aynı isimli 2 kategori olamaz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-3"></div>
                <div class="col-md-3">
                    <c:choose>
                        <c:when test="${kategorisil eq 1}">
                            <div class="alert alert-success">
                                Kategori silindi.
                            </div>
                        </c:when>
                        <c:when test="${kategorisil eq 2}">
                            <div class="alert alert-danger">
                                Kategori silinemedi.
                            </div>
                        </c:when>
                        <c:when test="${kategoriguncelle eq 1}">
                            <div class="alert alert-success">
                                Kategori ismi güncellendi.
                            </div>
                        </c:when>
                        <c:when test="${kategoriguncelle eq 2}">
                            <div class="alert alert-danger">
                                Kategori ismi güncellenemedi.
                            </div>
                        </c:when>
                        <c:when test="${kategoriguncelle eq 3}">
                            <div class="alert alert-warning">
                                ${kategoriadi} zaten oluşturulmuş.
                                Lütfen farklı bir isimle yeniden deneyin.
                            </div>
                        </c:when>
                    </c:choose>
                    <h3>Mecvut Kategoriler</h3>
                    <ol>
                        <c:forEach var="item" items="${categoryList}">
                            <c:if test="${item.id ne 0}">
                                <li>
                                    <h4 >
                                            ${item.categoryName }
                                        <a href="#editCategoryDialog"
                                           title="Düzenle"
                                           data-id="${item.id}"
                                           data-name="${item.categoryName}"
                                           class="open-editCategoryDialog"
                                           data-toggle="modal">
                                            <span style="color:dodgerblue" class="glyphicon glyphicon-pencil"></span>
                                        </a>
                                        <c:if test="${item.referencesCount eq 0 && fn:length(item.children) eq 0 && item.id ne 3}">
                                            <a href="#deleteCategoryDialog"
                                               title="Sil"
                                               data-id="${item.id}"
                                               class="open-deleteCategoryDialog"
                                               data-toggle="modal">
                                                <span style="color:red" class="glyphicon glyphicon-trash" title="Sil"></span>
                                            </a>
                                        </c:if>
                                    </h4>
                                    <ol>
                                        <c:forEach var="childItem" items="${item.children}">
                                            <li>
                                                <h4>
                                                        ${childItem.categoryName}
                                                    <a href="#editCategoryDialog"
                                                       title="Düzenle"
                                                       data-id="${childItem.id}"
                                                       data-name="${childItem.categoryName}"
                                                       class="open-editCategoryDialog"
                                                       data-toggle="modal">
                                                        <span style="color:dodgerblue" class="glyphicon glyphicon-pencil"></span>
                                                    </a>
                                                    <c:if test="${childItem.referencesCount eq 0}">
                                                        <a href="#deleteCategoryDialog"
                                                           title="Sil"
                                                           data-id="${childItem.id}"
                                                           class="open-deleteCategoryDialog"
                                                           data-toggle="modal">
                                                            <span style="color:red" class="glyphicon glyphicon-trash"></span>
                                                        </a>
                                                    </c:if>
                                                </h4>
                                            </li>
                                        </c:forEach>
                                    </ol>
                                </li>
                            </c:if>
                        </c:forEach>
                    </ol>
                </div>
                <div class="col-md-3">
                    <c:choose>
                        <c:when test="${kategorieklendi eq 1 }">
                            <div class="alert alert-success">
                                Kategori başarıyla eklendi.
                            </div>
                        </c:when>
                        <c:when test="${kategorieklendi eq 2 }">
                            <div class="alert alert-danger">
                                Kategori eklenirken bir hata meydana geldi.
                                Lütfen daha sonra tekrar deneyiniz.
                            </div>
                        </c:when>
                        <c:when test="${kategorieklendi eq 3 }">
                            <div class="alert alert-warning">
                                    ${kategoriadi} zaten oluşturulmuş.
                                Lütfen farklı bir isimle yeniden deneyin.
                            </div>
                        </c:when>
                    </c:choose>

                    <div class="panel panel-primary">
                        <div class="panel-heading"><p>Kategori Ekle</p></div>
                        <div class="panel-body">
                            <form action="../savecategory">
                                <div class="form-group">
                                    <label for="categoryNameID">Kategori Adı</label>
                                    <input type="text" class="form-control" id="categoryNameID" name="categoryName"
                                           maxlength="70" required title="Lütfen bir isim giriniz">
                                </div>
                                <div class="form-group">
                                    <label for="sel1">Üst Kategori Seç</label>
                                    <select class="form-control" id="sel1" name="parentCategory">
                                        <c:forEach var="item" items="${categoryList}">
                                            <option value="${item.id}">
                                                <c:out value="${item.categoryName}"/>
                                            </option>
                                        </c:forEach>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Ekle</button>
                            </form>
                        </div>
                        <div class="panel-footer">
                            Ana kategeri eklemek için üst kategori olarak "root-category" 'i seçin.
                        </div>
                    </div>

                </div>
            </div>
        </div>
        <jsp:include page="html/footer.html"/>
    </body>
</html>