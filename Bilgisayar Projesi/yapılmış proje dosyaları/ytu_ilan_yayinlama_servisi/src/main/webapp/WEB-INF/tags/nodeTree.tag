<%@tag description="display the whole nodeTree" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<%@attribute name="node" type="com.myapp.Node" required="true" %>
<%@taglib prefix="template" tagdir="/WEB-INF/tags" %>
<li>${node.name}
<c:if test="${fn:length(node.childs) > 0}">
    <ul>
    <c:forEach var="child" items="${node.childs}">
        <template:nodeTree node="${child}"/>
    </c:forEach>
    </ul>
</c:if>
</li>