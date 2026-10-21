import React, { Fragment, useContext, useState } from "react";
import { DataTable } from "primereact/datatable";
import { Column } from "primereact/column";
import {
  travelApi,
  travelApproveApi,
  usersApi,
  profileApi,
} from "../api/apiFunctions";
import useSWR, { mutate } from "swr";
import TokenContext from "../../contexts/tokenContext";
import { useHistory } from "react-router-dom";
import Navbar from "../Navbar/index";
import style from "./styles.module.css";
import { FilterMatchMode } from "primereact/api";
import { apiBaseUrl } from '../../config/apiConfig';

function Travels() {
  const [currentPage, setCurrentPage] = useState(1);
  const apiUrl = apiBaseUrl;
  const history = useHistory();
  // const { accessToken, refreshToken } = useContext(TokenContext);
  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");

  const { data, isLoading } = useSWR(
    `${apiUrl}/travel${currentPage}`,
    async (url) => {
      const response = await travelApi(accessToken, currentPage, "GET");
      return response;
    }
  );

  const { data: userList, isLoading: userListIsLoading } = useSWR(
    `${apiUrl}/auth/users`,
    async (url) => {
      const response = await usersApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  const { data: accountantData, isLoading: accountantIsLoading } = useSWR(
    `${apiUrl}/auth/me`,
    async (url) => {
      const response = await profileApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  const findUserByName = (username) => {
    const user = userList.find((user) => user.username === username);
    return user ? `${user.name} ${user.surname} (${user.email} - ${user.username})` : "";
  };

  const onPageChange = (event) => {
    //setCurrentPage(event.first / event.rows + 1);
    setCurrentPage(currentPage+1);

    // Update the API URL with the new page value
    const newApiUrl = `${apiUrl}/travel${currentPage}`;
    mutate(newApiUrl);
  };

  const renderDetailsButton = (rowData) => {
    return (
      <button
        className={style.button}
        onClick={() => handleDetailsClick(rowData)}
      >
        Details
      </button>
    );
  };

  const handleDetailsClick = (rowData) => {
    history.push(`/travel-details/${rowData._id}`);
  };

  const renderApproveButton = (rowData) => {
    return (
      <button
        className={style.button}
        style={{ color: "green" }}
        onClick={() => handleApproveClick(rowData)}
      >
        Approve
      </button>
    );
  };

  const renderRejectButton = (rowData) => {
    return (
      <button
        className={style.button}
        style={{ color: "red" }}
        onClick={() => handleRejectClick(rowData)}
      >
        Reject
      </button>
    );
  };

  const handleApproveClick = async (rowData) => {
    const aprovalStatus = "approved";
    const currentDate = new Date();
    const day = String(currentDate.getDate()).padStart(2, "0");
    const month = String(currentDate.getMonth() + 1).padStart(2, "0");
    const year = currentDate.getFullYear();
    const date = `${day}.${month}.${year}`;
    const accountant = accountantData.username;
    await travelApproveApi(
      accessToken,
      rowData._id,
      aprovalStatus,
      date,
      accountant
    );
    await mutate(`${apiUrl}/travel${currentPage}`);
  };

  const handleRejectClick = async (rowData) => {
    const aprovalStatus = "rejected";
    const currentDate = new Date();
    const day = String(currentDate.getDate()).padStart(2, "0");
    const month = String(currentDate.getMonth() + 1).padStart(2, "0");
    const year = currentDate.getFullYear();
    const date = `${day}.${month}.${year}`;
    const accountant = accountantData.username;
    await travelApproveApi(
      accessToken,
      rowData._id,
      aprovalStatus,
      date,
      accountant
    );
    await mutate(`${apiUrl}/travel${currentPage}`);
  };

  let counter = -1;
  const rowClassName = (rowData, rowIndex) => {
    counter++;
    return counter % 2 === 0 ? style.evenRow : style.oddRow;
  };

  const renderSuspiciousCell = (rowData) => {
    const cellStyle = {
      color: rowData.suspicious === "yes" ? "red" : "green",
    };

    return <span style={cellStyle}>{rowData.suspicious}</span>;
  };

  const renderStatusCell = (rowData) => {
    let cellStyle = { color: "black" };
    if (rowData.status === "approved") {
      cellStyle = { color: "green" };
    }
    if (rowData.status === "rejected") {
      cellStyle = { color: "red" };
    }
    return <span style={cellStyle}>{rowData.status}</span>;
  };

  return (
    <Fragment>
      <Navbar />
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center">
            <div className="card">
              <h2 className="pt-3">Travels</h2>
              {!isLoading && !userListIsLoading && !accountantIsLoading && (
                <DataTable
                  className={style.customDatatable}
                  value={data ? data.reverse() : []}
                  tableStyle={{ minWidth: "50rem", maxWidth: "100%" }}
                  rowClassName={rowClassName}
                  onPageChange={onPageChange}
                  paginator={true}
                  rows={5}
                  totalRecords={data ? data.length : 0}
                  filterDisplay="row"
                  scrollable="vertical" 
                  scrollHeight="500px"
                >
                  <Column
                    className={style.customColumn}
                    field="employeeUsername"
                    header="Employee"
                    body={(rowData) => findUserByName(rowData.employeeUsername)}
                    filter
                    filterField="employeeUsername"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="travelDate"
                    header="Travel Date"
                    filter
                    filterField="travelDate"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="startLocation"
                    header="Start Location"
                    filter
                    filterField="startLocation"
                    showFilterMenu={false}
                    filterMatchMode={FilterMatchMode.CONTAINS}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="endLocation"
                    header="End Location"
                    filter
                    filterField="endLocation"
                    showFilterMenu={false}
                    filterMatchMode={FilterMatchMode.CONTAINS}
                  ></Column>
                  {/* <Column className={style.customColumn} field="invoicePhoto" header="Invoice Photo"></Column> */}
                  {/* <Column className={style.customColumn} field="invoiceInfo" header="Invoice Info"></Column> */}
                  {/* <Column className={style.customColumn} field="invoiceNote" header="Invoice Note"></Column> */}
                  <Column
                    className={style.customColumn}
                    field="invoicePrice"
                    header="Invoice Price (TL)"
                    sortable
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="priceEstimate"
                    header="Price Estimate (TL)"
                    sortable
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="suspicious"
                    header="Suspicious"
                    body={renderSuspiciousCell}
                    filter
                    filterField="suspicious"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="status"
                    header="Status"
                    body={renderStatusCell}
                    filter
                    filterField="status"
                    showFilterMenu={false}
                  ></Column>
                  {/* <Column
                    className={style.customColumn}
                    field="approveByAccountant"
                    header="Approve/Reject By Accountant"
                    body={(rowData) =>
                      findUserByName(rowData.approveByAccountant)
                    }
                    filter
                    filterField="approveByAccountant"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="approveDate"
                    header="Approve/Reject Date"
                    filter
                    filterField="approveDate"
                    showFilterMenu={false}
                  ></Column> */}
                  <Column
                    className={style.customDetailsColumn}
                    header="Details"
                    body={renderDetailsButton}
                  ></Column>
                  <Column
                    className={style.customApproveColumn}
                    header="Approve"
                    body={renderApproveButton}
                  ></Column>
                  <Column
                    className={style.customRejectColumn}
                    header="Reject"
                    body={renderRejectButton}
                  ></Column>
                </DataTable>
              )}
            </div>
          </div>
        </div>
      </div>
    </Fragment>
  );
}

export default Travels;
