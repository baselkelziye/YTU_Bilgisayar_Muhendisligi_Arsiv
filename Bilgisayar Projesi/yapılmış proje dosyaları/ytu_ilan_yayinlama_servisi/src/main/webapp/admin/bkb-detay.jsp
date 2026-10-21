<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 22.12.2016
  Time: 03:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <title>BKB DETAY</title>
        <jsp:include page="html/head.html"/>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>
    </head>
    <body>
        <script>
            $(document).on("click", ".open-deleteUserDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var username = _self.data('username');
                $("#username").val(username);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-deleteAccountDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var iban = _self.data('iban');
                $("#iban").val(iban);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-updateAccountDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var iban = _self.data('iban');
                var bankName = _self.data('bankname');
                var nameOfBranch = _self.data('nameofbranch');
                var accountNumber = _self.data('accountnumber');

                $("#iban2").val(iban);
                $("#newIban").val(iban);
                $("#bank_name").val(bankName);
                $("#name_of_branch").val(nameOfBranch);
                $("#account_number").val(accountNumber);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="addNewUserDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                            <h4 class="modal-title">Kullanıcı Ekleyin</h4>
                    </div>
                    <div class="modal-body">
                        <form method="post" action="../userexistdau">
                            <table id="formUserTable" class="table">
                                <tbody>
                                <tr>
                                    <td>Kullanıcı Adı</td>
                                    <td><input type="text" name="username" class="form-control"
                                               pattern=".{3,20}" required title="Kullanıcı adı 3-20 karakter aralığında olmalıdır"/></td>
                                </tr>
                                <tr>
                                <tr>
                                    <td>Geçici Parola</td>
                                    <td><input type="password" name="password"
                                               pattern=".{6,16}" class="form-control"
                                               required title="Parola en az 6 an fazla 16 karakter olabilir."/></td>
                                </tr>
                                <tr>
                                    <td>Geçici Parola(Tekrar)</td>
                                    <td><input type="password" name="password"
                                               pattern=".{6,16}" class="form-control"
                                               required title="Parola en az 6 an fazla 16 karakter olabilir."/></td>
                                </tr>
                                <tr>
                                    <td><b>Yetkilinin:</b></td>
                                </tr>
                                <td>Adı</td>
                                <td><input type="text" name="name" class="form-control"
                                           pattern=".{3,40}" required title="İsim 3-40 karakter aralığında olmalıdır"></td>
                                </tr>
                                <tr>
                                    <td>Soyadı</td>
                                    <td><input type="text" name="surname" class="form-control"
                                               pattern=".{3,20}" required title="Soyisim 3-40 karakter aralığında olmalıdır"></td>
                                </tr>
                                <tr>
                                    <td>Mail Adresi</td>
                                    <td>
                                        <input type="email" name="contactMail" id="contactMail" class="form-control" value="${contactMail}"
                                               pattern=".{3,40}">
                                    </td>
                                </tr>
                                <tr>
                                    <td>Telefon Numarası</td>
                                    <td>
                                        <input type="text" name="contactTel" id="contactTel" class="form-control" value="${contactTel}"
                                               pattern="[0-9]{0,11}" maxlength="11"
                                               required title="Telefon numarası 11 karakter aralığında olmalıdır">
                                    </td>
                                </tr>
                                <tr><td colspan="2"><button type="submit" class="btn btn-default">Kullanıcı Ekle</button></td></tr>
                                </tbody>
                            </table>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="addNewAccountDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel4" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Hesap Ekleyin</h4>
                    </div>
                    <div class="modal-body">
                        <form method="post" action="../accountexistdau">
                            <table id="formTable" class="table">
                                <tbody>
                                <tr>
                                    <td>Banka Adı</td>
                                    <td><input type="text" name="bank_name" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Şube Adı</td>
                                    <td><input type="text" name="name_of_branch" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Hesap No</td>
                                    <td><input type="text" name="account_number" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Para Birimi</td>
                                    <td> <select disabled name="currency" class="form-control">
                                        <c:forEach var="item" items="${curr}">
                                            <option value="${item.id}">
                                                <c:out value="${item.title}"/>
                                            </option>
                                        </c:forEach>
                                    </select></td>
                                </tr>
                                <tr>
                                    <td>IBAN</td>
                                    <td><input type="text" name="iban"/></td>
                                </tr>
                                <tr><td colspan="2"><button type="submit" class="btn btn-default">Banka Hesabı Oluştur</button></td></tr>
                                </tbody>
                            </table>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="updateAccountDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel4" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Hesap Bilgilerini Düzenleyin</h4>
                    </div>
                    <div class="modal-body">
                        <form method="post" action="../updateaccount">
                            <table id="formTable2" class="table">
                                <tbody>
                                <tr>
                                    <td>Banka Adı</td>
                                    <td><input id="bank_name" type="text" name="bank_name" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Şube Adı</td>
                                    <td><input type="text" id="name_of_branch" name="name_of_branch" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Hesap No</td>
                                    <td><input type="text" id="account_number" name="account_number" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>IBAN</td>
                                    <td><input type="text" id="newIban" name="newIban" class="form-control"/></td>
                                </tr>
                                <tr>
                                    <td>Para Birimi</td>
                                    <td> <select disabled name="currency" class="form-control">
                                        <c:forEach var="item" items="${curr}">
                                            <option value="${item.id}">
                                                <c:out value="${item.title}"/>
                                            </option>
                                        </c:forEach>
                                    </select></td>
                                </tr>
                                <input type="hidden" name="iban" id="iban2">
                                <tr><td colspan="2"><button type="submit" class="btn btn-default">Güncelle</button></td></tr>
                                </tbody>
                            </table>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="deleteUserDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Kullanıcıyı Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="username" id="username">
                            <input formaction="../deletedauuser" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Muhasebe kaydı olan kayıtlar silinemez. </p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="deleteAccountDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Banka Hesabı Sil!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form>
                            <input type="hidden" name="iban" id="iban">
                            <input formaction="../deleteaccount" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Üzerine paket tanımlı olan hesaplar silinemez. </p>
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
                    <a href="../displaydauservlet" class="btn btn-info"><span class="glyphicon glyphicon-arrow-left"></span> Listeye Dön</a>
                </div>
                <div class="col-md-6">
                    <b><p align="center">${dau.unitName} Birimi İçin Detay<p></b>
                </div>
            </div>
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-5">
                    <a href="#addNewUserDialog" data-toggle="modal" class="btn btn-success">Kullanıcı Ekle</a>
                    <br/>
                    <br/>
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Tanımlı Kullanıcılar</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${kullanicieklendi eq 1}">
                                    <div class="alert alert-success">
                                        Kullanıcı eklendi.
                                    </div>
                                </c:when>
                                <c:when test="${kullanicieklendi eq 2}">
                                    <div class="alert alert-danger">
                                        Bir hata oluştu.
                                    </div>
                                </c:when>
                                <c:when test="${kullanicieklendi eq 3}">
                                    <div class="alert alert-warning">
                                        Eklenemedi. Kullanıcı adı mevcut.
                                    </div>
                                </c:when>
                            </c:choose>

                            <c:choose>
                                <c:when test="${kullanicisil eq 1}">
                                    <div class="alert alert-success">
                                        Kullanıcı silindi.
                                    </div>
                                </c:when>
                                <c:when test="${kullanicisil eq 2}">
                                    <div class="alert alert-danger">
                                        Kullanıcı silinemedi.
                                    </div>
                                </c:when>
                            </c:choose>
                            <table class="table table-stripped">
                                <thead>
                                <tr>
                                    <th>Kullanıcı Adı</th>
                                    <th>Adı</th>
                                    <th>Soyadı</th>
                                    <th>Telefon</th>
                                    <th>Mail</th>
                                    <th>İşlem</th>
                                </tr>
                                </thead>
                                <tbody>
                                <c:forEach var="item" items="${dau.dauUser}">
                                    <tr>
                                        <td>${item.userName}</td>
                                        <td>${item.name}</td>
                                        <td>${item.surname}</td>
                                        <td>
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Telefon Numarası" data-content="${item.contactTel}">
                                                <span class="glyphicon glyphicon-earphone btn btn-success"></span>
                                            </a>
                                        </td>
                                        <td>
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="E-posta" data-content="${item.contactMail}">
                                                <span class="glyphicon glyphicon-envelope btn btn-info"></span>
                                            </a>
                                        </td>
                                        <td>
                                            <a
                                                data-toggle="modal"
                                                href="#deleteUserDialog"
                                                class="open-deleteUserDialog"
                                                data-username="${item.userName}"
                                                title="Sil">
                                                <span class="glyphicon glyphicon-trash btn btn-danger"></span>
                                            </a>
                                        </td>
                                    </tr>
                                </c:forEach>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
                <div class="col-md-6">
                    <a href="#addNewAccountDialog" data-toggle="modal" class="btn btn-success">Hesap Ekle</a>
                    <br/>
                    <br/>
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Tanımlı Banka Hesapları</p>
                        </div>
                        <div class="panel-body">
                            <table class="table table-stripped">
                                <thead>
                                    <tr>
                                        <th>Banka Adı</th>
                                        <th>Şube Adı</th>
                                        <th>Hesap No</th>
                                        <th>İşlem</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <c:choose>
                                        <c:when test="${hesapsil eq 1}">
                                            <div class="alert alert-success">
                                                Hesap silindi.
                                            </div>
                                        </c:when>
                                        <c:when test="${hesapsil eq 2}">
                                            <div class="alert alert-danger">
                                                Hesap silinemedi.
                                            </div>
                                        </c:when>
                                        <c:when test="${hesapeklendi eq 1}">
                                            <div class="alert alert-success">
                                                Hesap eklendi
                                            </div>
                                        </c:when>
                                        <c:when test="${hesapsil eq 2}">
                                            <div class="alert alert-danger">
                                                Hesap eklendi.
                                            </div>
                                        </c:when>
                                        <c:when test="${hesapguncellendi eq 2}">
                                            <div class="alert alert-danger">
                                                Hesap güncellenemedi.
                                            </div>
                                        </c:when>
                                        <c:when test="${hesapguncellendi eq 1}">
                                            <div class="alert alert-success">
                                                Hesap güncellendi.
                                            </div>
                                        </c:when>
                                    </c:choose>

                                    <c:forEach var="item" items="${dau.account}">
                                        <tr>
                                            <td>${item.bankName}</td>
                                            <td>${item.branchBankName}</td>
                                            <td>${item.bankAccountNumber}</td>
                                            <th>
                                                <a href="#" data-toggle="popover" data-placement="left"
                                                   title="IBAN" data-content="${item.iban}">
                                                    <span class="glyphicon glyphicon-barcode btn btn-info"></span>
                                                </a>
                                                <a
                                                    data-toggle="modal"
                                                    href="#updateAccountDialog"
                                                    class="open-updateAccountDialog"
                                                    data-nameofbranch="${item.branchBankName}"
                                                    data-accountnumber="${item.bankAccountNumber}"
                                                    data-bankname="${item.bankName}"
                                                    data-iban="${item.iban}"
                                                    title="Düzenle">
                                                    <span class="glyphicon glyphicon-pencil btn btn-success"></span>
                                                </a>
                                                <a
                                                    data-toggle="modal"
                                                    href="#deleteAccountDialog"
                                                    class="open-deleteAccountDialog"
                                                    data-iban="${item.iban}"
                                                    title="Sil">
                                                    <span class="glyphicon glyphicon-trash btn btn-danger"></span>
                                                </a>
                                            </th>
                                        </tr>
                                    </c:forEach>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/footer.html"/>
    </body>
</html>
