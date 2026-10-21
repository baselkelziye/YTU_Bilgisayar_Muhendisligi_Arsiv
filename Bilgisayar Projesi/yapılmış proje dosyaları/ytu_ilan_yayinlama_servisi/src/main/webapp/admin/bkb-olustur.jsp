<%-- 
    Document   : createdonationacceptunit
    Created on : 28.Nis.2016, 18:36:16
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Yeni BKB</title>
        <jsp:include page="html/head.html"/>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="text-centers">
                        <div class="panel panel-primary">
                            <div class="panel-heading">
                                <h4>Yeni Bağış Kabul Birimi Ekleyin</h4>
                            </div>
                            <div class="panel-body">
                                <c:choose>
                                    <c:when test="${vakifolusturuldu eq 1}">
                                        <div id="alert" class="alert alert-success">
                                            <strong>Başarılı!</strong> BKB Oluşturuldu
                                        </div>
                                    </c:when>
                                    <c:when test="${vakifolusturuldu eq 2}">
                                        <div id="alert" class="alert alert-danger">
                                            <strong>Başarısız!</strong> BKB Oluşturulamadı.
                                        </div>
                                    </c:when>
                                </c:choose>
                                <form method="post" action="../createdonationunitservlet" >
                                    <table id="formBKBTable" class="table">
                                        <tbody>
                                        <tr>
                                            <td>Birimin Adı</td>
                                            <td><input type="text" name="unit_name" class="form-control"
                                                       pattern=".{3,40}" required title="BKB adı 3-40 karakter aralığında olmalıdır"/></td>
                                        </tr>
                                        <tr><td colspan="2"><button type="submit" class="btn btn-success">BKB Oluştur</button></td></tr>
                                        </tbody>
                                    </table>
                                </form>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <h4>Kullanıcı Ekleyin</h4>
                            <h5>
                                <c:choose>
                                    <c:when test="${dau ne null}">
                                        ${dau.unitName} için
                                    </c:when>
                                </c:choose>
                            </h5>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${kullanicieklendi eq 1}">
                                    <div id="alert" class="alert alert-success">
                                        <strong>Başarılı!</strong> Kullanıcı Oluşturuldu
                                    </div>
                                </c:when>
                                <c:when test="${kullanicieklendi eq 2}">
                                    <div id="alert" class="alert alert-danger">
                                        <strong>Başarısız!</strong> Kullanıcı Oluşturulamadı
                                    </div>
                                </c:when>
                                <c:when test="${kullanicieklendi eq 3}">
                                    <div id="alert" class="alert alert-danger">
                                        <strong>Başarısız!</strong> Bu kullanıcı adı zaten alınmış.
                                    </div>
                                </c:when>
                                <c:when test="${kullanicieklendi eq 4}">
                                    <div id="alert" class="alert alert-warning">
                                        <strong>BKB yok!</strong> Lütfen önce BKB tanımlayın.
                                        Tanımlanmış bir BKB için <a href="admin/bkb-duzenle.jsp">buradan</a>
                                        kullanıcı ekleyebilirsiniz.
                                    </div>
                                </c:when>
                            </c:choose>
                            <form method="post" action="../adddauuserservlet">
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
                                                   pattern="[0-9]{11,11}"  maxlength="11"
                                                   required title="Telefon numarası 11 karakter aralığında olmalıdır">
                                        </td>
                                    </tr>
                                    <tr><td colspan="2"><button type="submit" class="btn btn-success">Kullanıcı Ekle</button></td></tr>
                                    </tbody>
                                </table>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <h4>Banka Hesabı Ekleyin</h4>
                            <h5>
                                <c:choose>
                                    <c:when test="${dau ne null}">
                                        ${dau.unitName} için
                                    </c:when>
                                </c:choose>
                            </h5>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${hesapeklendi eq 1}">
                                    <div id="alert" class="alert alert-success">
                                        <strong>Başarılı!</strong> Banka hesabı eklendi
                                    </div>
                                </c:when>
                                <c:when test="${hesapeklendi eq 2}">
                                    <div id="alert" class="alert alert-danger">
                                        <strong>Başarısız!</strong> Banka hesabı eklenemedi
                                    </div>
                                </c:when>
                                <c:when test="${hesapeklendi eq 4}">
                                    <div id="alert" class="alert alert-warning">
                                        <strong>BKB yok!</strong> Lütfen önce BKB tanımlayın.
                                        Tanımlanmış bir BKB için <a href="admin/bkb-duzenle.jsp">buradan</a>
                                        banka hesabı ekleyebilirsiniz.
                                    </div>
                                </c:when>
                            </c:choose>
                            <form method="post" action="../addbankaccountservlet">
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
                                    <tr><td colspan="2"><button type="submit" class="btn btn-success">Banka Hesabı Oluştur</button></td></tr>
                                    </tbody>
                                </table>
                            </form>
                        </div>
                    </div>
                 </div>
            </div>
        </div>

        <jsp:include page="html/footer.html"/>
    </body>
</html>
