import React, { Fragment, useContext, useState } from "react";
import { DataTable } from "primereact/datatable";
import { Column } from "primereact/column";
import {
    createPlanApi,
    getPlansListApi,
    updatePlanApi,
    deletePlanApi,
    profileApi,
    usersApi,
    citiesApi
  } from "../api/apiFunctions";
import useSWR, { mutate } from "swr";
import TokenContext from "../../contexts/tokenContext";
import Navbar from "../Navbar/index";
import style from "./styles.module.css";
import UpdatePopup from "./updatePopup";
import CreatePopup from "./createPopup";
import { Button } from "bootstrap";
import { apiBaseUrl } from '../../config/apiConfig';

function TaxiFeeList() {
  const [currentPage, setCurrentPage] = useState(1);
  const apiUrl = apiBaseUrl;
  //const { accessToken, refreshToken } = useContext(TokenContext);
  let accessToken = sessionStorage.getItem("accessToken");
  let refreshToken = sessionStorage.getItem("refreshToken");
  const [newOpeningFee, setNewOpeningFee] = useState(0);
  const [newFeePerKm, setNewFeePerKm] = useState(0);
  const [showUpdatePopup, setShowUpdatePopup] = useState(false);
  const [showCreatePopup, setShowCreatePopup] = useState(false);
  const [rowData, setRowData] = useState("");

  const { data, isLoading } = useSWR(
    `${apiUrl}/plan${currentPage}`,
    async (url) => {
      const response = await getPlansListApi(accessToken, currentPage, "GET");
      return response;
    }
  );

  const { data: meData, isLoading: meIsLoading } = useSWR(`${apiUrl}/auth/me`, async (url) => {
    const response = await profileApi(accessToken, refreshToken, "POST");
    return response;
  });

  const { data: employeeList, isLoading: userListIsLoading } = useSWR(
    `${apiUrl}/auth/users`,
    async (url) => {
      const response = await usersApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  const { data: cities, isLoading: citiesIsLoading } = useSWR(
    `${apiUrl}/fee/cities`,
    async (url) => {
      const response = await citiesApi(accessToken, refreshToken, "POST");
      return response;
    }
  );

  console.log("cities:", cities)

  const findUserByName = (username) => {
    const user = employeeList.find((user) => user.username === username);
    return user ? `${user.name} ${user.surname} (${user.email} - ${user.username})` : "";
  };

  const onPageChange = (event) => {
    setCurrentPage(event.first / event.rows + 1);
  };

  const handleCreate = async () => {
    setShowCreatePopup(true);
    await mutate(`${apiUrl}/plan`);
  };

  const renderUpdateButton = (rowData) => {
    return (
      <button
        className={style.button}
        style={{ color: "green" }}
        onClick={() => handleUpdate(rowData)}
      >
        Update
      </button>
    );
  };

  const handleUpdate = async (rowData) => {
    setRowData(rowData);
    setShowUpdatePopup(true);
    await mutate(`${apiUrl}/plan/${rowData._id}`);
  };

  const closePopup = () => {
    setShowUpdatePopup(false);
    setShowCreatePopup(false);
  };

  const renderDeleteButton = (rowData) => {
    return (
      <button
        className={style.button}
        style={{ color: "red" }}
        onClick={() => handleDelete(rowData)}
      >
        Delete
      </button>
    );
  };

  const handleDelete = async (rowData) => {
    await deletePlanApi(
      accessToken,
      rowData._id,
    );
    await mutate(`${apiUrl}/plan/${rowData._id}`);
  };

  return (
    <Fragment>
      <Navbar />
      <div className="container mt-3 mb-3">
        <div className="row d-flex justify-content-between">
          <div className="login-card d-flex flex-column align-items-center">
            <div className="pb-3">
              <button
                className={style.button}
                style={{ color: "green", marginLeft: "250%" }}
                onClick={() => handleCreate()}
              >
              Create
              </button>
            </div>
            <div className="card">
              <h2 className="pt-3">Travel Plan List</h2>
              {/* {!isLoading && !userListIsLoading && !accountantIsLoading && ( */}
              {(
                <DataTable
                  className={style.customDatatable}
                  value={data}
                  tableStyle={{ minWidth: "50rem", maxWidth: "100%" }}
                //   rowClassName={rowClassName}
                  onPageChange={onPageChange}
                  paginator={true}
                  rows={5}
                  totalRecords={data ? data.length : 0}
                  filterDisplay={(!showCreatePopup && !showUpdatePopup) ? "row" : false}
                  scrollable={(!showCreatePopup && !showUpdatePopup) ? "vertical" : false}
                  scrollHeight={(!showCreatePopup && !showUpdatePopup) ? "500px" : false}
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
                    field="endLocation"
                    header="Destination"
                    filter
                    filterField="endLocation"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="accountantUsername"
                    header="Assigned By Accountant"
                    body={(rowData) => findUserByName(rowData.accountantUsername)}
                    filter
                    filterField="accountantUsername"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customDetailsColumn}
                    header="Update"
                    body={renderUpdateButton}
                  ></Column>
                  <Column
                    className={style.customApproveColumn}
                    header="Delete"
                    body={renderDeleteButton}
                  ></Column>
                </DataTable>
              )}
            </div>
          </div>
        </div>
      </div>
      <div id="popup-update"></div>
      {showUpdatePopup && !meIsLoading && !userListIsLoading && !citiesIsLoading && (
        <UpdatePopup
          onClose={closePopup}
          rowData={rowData}
          accessToken={accessToken}
          cityList={cities}
          meData={meData}
          style={style.popupStyle}
        />
      )}
      <div id="popup-create"></div>
      {showCreatePopup && !meIsLoading && !userListIsLoading && !citiesIsLoading && (
        <CreatePopup
          accessToken={accessToken}
          meData={meData}
          employeeList={employeeList}
          cityList={cities}
          onClose={closePopup}
          style={style.popupStyle}
        />
      )}
    </Fragment>
  )
};

export default TaxiFeeList;
