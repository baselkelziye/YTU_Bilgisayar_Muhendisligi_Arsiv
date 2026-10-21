<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
    
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html">
		<meta charset="UTF-8">
		<jsp:include page="html/head.html"/>
		<title>Bölümler</title>
	</head>
	<body>
		<script>
			$(document).on("click", ".open-deleteDepartmentDialog", function (e) {
				e.preventDefault();			
				var _self = $(this);		
				var code = _self.data('id');
				$("#code").val(code);						
				$(_self.attr('href')).modal('show');
			});

			$(document).on("click", ".open-changeDepartmentDialog", function (e) {
				e.preventDefault();
				var _self = $(this);
				var code = _self.data('code');
				var name = _self.data('name');
				$("#codeChange").val(code);
                $("#oldCode").val(code);
				$("#name").val(name);
				$(_self.attr('href')).modal('show');
			});
		</script>

		<div class="modal fade" id="deleteDepartmentDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" aria-hidden="true">
			<div class="modal-dialog">
				<!-- Modal content-->
				<div class="modal-content">
 					<div class="modal-header">
    					<button type="button" class="close" data-dismiss="modal">&times;</button>
    					<h4 class="modal-title">Bölümü Sil!</h4>
  					</div>
  					<div class="modal-body">
   						<p>Silmek İstediğinize Emin Misiniz?</p>
   						<form>
   							<input type="hidden" name="code" id="code">
   							<input formaction="../deletedepartment" type="submit" class="btn btn-default" value="Evet">
   							<button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
   						</form>						      		      
					</div>
 					<div class="modal-footer">   	
 						<p>Kullanımda olan bölümler silinemez. </p>
   						<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
 					</div>
				</div>
			</div>
		</div>
		
		<div class="modal fade" id="changeDepartmentDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
			<div class="modal-dialog">
				<!-- Modal content-->
				<div class="modal-content">
 					<div class="modal-header">
    					<button type="button" class="close" data-dismiss="modal">&times;</button>
    					<h4 class="modal-title">Bilgileri Düzenleyin</h4>
  					</div>
  					<div class="modal-body">
   						<p>Değiştirmek istediğiniz bilgiler..</p>
   						<form method="post" action="../updatedepartment">
                            <input type="hidden" name="oldCode" id="oldCode">
   							<div class="form-group">
   								<label for="codeChange">Bölüm Kodu</label>
   								<input type="text" name="codeChange" id="codeChange" class="form-control"
									   maxlength="3" required title="Bölüm kodu 3 karakter olmalıdır.">
   							</div>
   							<div class="form-group">
   								<label for="name">Bölüm Adı</label>
   								<input type="text" name="name" id="name" class="form-control"
                                    maxlength="50" required title="Bölüm adı 1-50 karakter uzunluğunda olmalı">
   							</div>
   							<input type="submit" class="btn btn-default" value="Güncelle">
   						</form>
					</div>
 					<div class="modal-footer">
 						<p>Bölüm kodunun var olan bir kod olması durumunda bilgiler güncellenmez. </p>
   						<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
 					</div>
				</div>
			</div>
		</div>

        <jsp:include page="html/menu.html"/>

		<div class="jumbotron container-fluid">
        	<div class="row">
                <div class="col-md-2"></div>
            	<div class="col-md-5">
            		<table class="table table-hover">
            			<thead>
            				<tr>
            					<th>Bölüm Kodu</th>
            					<th>Bölüm Adı</th>
            					<th>İşlem</th>
            				</tr>				
            			</thead>
            			<tbody>
            				<c:choose>
            					<c:when test="${bolumsil eq 1 }">
            						<div class="alert alert-success">
            							Bölüm silindi.
            						</div>
            					</c:when>
            					<c:when test="${bolumsil eq 2 }">
            						<div class="alert alert-danger">
            							Bölüm silinirken bir hata meydana geldi.
            						</div>
            					</c:when>
                                <c:when test="${bolumguncelle eq 1 }">
                                    <div class="alert alert-success">
                                        Bölüm bilgileri güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${bolumguncelle eq 2 }">
                                    <div class="alert alert-danger">
                                        Güncelleme işlemi başarısız. Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
            				</c:choose>
            				<c:forEach var="item" items="${departmentList }">
            					<tr>
            						<td>${item.code }</td>
            						<td>${item.name }
            						<td>
            							<form>
            								<input type="hidden" value="${item.code }" name="code">
            								<a data-code="${item.code }"
            									data-name="${item.name }"
											    data-toggle="modal"
            									title="Düzenle"
            									class="open-changeDepartmentDialog btn btn-info"
            									href="#changeDepartmentDialog">
            									<span class="glyphicon glyphicon-pencil"></span>
            								</a>
											<a data-id="${item.code }" 
												data-toggle="modal" 
												title="Sil" 
												class="open-deleteDepartmentDialog btn btn-danger"
												href="#deleteDepartmentDialog">
												<span class="glyphicon glyphicon-trash"></span>
											</a>            							
										</form>
            						<td>
            					</tr>
            				</c:forEach>
            			</tbody>
            		</table>
            	</div>
                <div class="col-md-1"></div>
            	<div class="col-md-2">
            		<c:choose>
            			<c:when test="${bolumekle eq 1 }">
            				<div class="alert alert-success">
            					Yeni bölüm eklendi.
            				</div>
            			</c:when>
            			<c:when test="${bolumekle eq 2 }">
            				<div class="alert alert-warning">
            					İşlem gerçekleşmedi.Girmiş olduğunuz bölüm kodu sistemde mevcut.
            				</div>
            			</c:when>
            			<c:when test="${bolumekle eq 3 }">
            				<div class="alert alert-danger">
            					Bir hata meydana geldi. Lütfen daha sonra tekrar deneyiniz.
            				</div>
            			</c:when>
            		</c:choose>
                    <div class="panel panel-primary">
                        <div class="panel-heading">Bölüm Ekle</div>
                        <div class="panel-body">
                            <form method="post" action="../adddepartment">
                                <div class="form-group">
                                    <label for="dcode">Bölüm Kodu</label>
                                    <input type="text" name="dcode" id="dcode" class="form-control"
                                           maxlength="3" required title="Bölüm kodu 3 karakter olmalıdır.">
                                </div>
                                <div class="form-group">
                                    <label for="dname">Bölüm Adı</label>
                                    <input type="text" name="dname" id="dname" class="form-control"
                                           maxlength="50" required title="Bölüm adı 1-50 karakter uzunluğunda olmalı">
                                </div>
                                <button type="submit" class="btn btn-success">Ekle</button>
                            </form>
                        </div>
                    </div>
            	</div>
           	</div>
        </div>

        <jsp:include page="html/footer.html"/>
	</body>
</html>