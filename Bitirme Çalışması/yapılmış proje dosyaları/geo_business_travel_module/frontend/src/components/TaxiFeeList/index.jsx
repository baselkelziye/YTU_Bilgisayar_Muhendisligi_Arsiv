import React, { Fragment, useContext, useState } from "react";
import { DataTable } from "primereact/datatable";
import { Column } from "primereact/column";
import {
    createCityApi,
    getCityListApi,
    updateCityApi,
    deleteCityApi,
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
  const [updateCity, setUpdateCity] = useState("");

  const { data, isLoading } = useSWR(
    `${apiUrl}/fee${currentPage}`,
    async (url) => {
      const response = await getCityListApi(accessToken, currentPage, "GET");
      return response;
    }
  );

  const onPageChange = (event) => {
    setCurrentPage(event.first / event.rows + 1);
  };

  const handleCreate = async () => {
    setShowCreatePopup(true);
    await mutate(`${apiUrl}/fee`);
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
    setUpdateCity(rowData);
    setShowUpdatePopup(true);
    await mutate(`${apiUrl}/fee${rowData.city}`);
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
    await deleteCityApi(
      accessToken,
      rowData.city,
    );
    await mutate(`${apiUrl}/fee${rowData.city}`);
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
              <h2 className="pt-3">Taxi Fee List</h2>
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
                    field="city"
                    header="City"
                    filter
                    filterField="city"
                    showFilterMenu={false}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="openingFee"
                    header="Opening Fee (TL)"
                    sortable={(!showCreatePopup && !showUpdatePopup) ? "true" : "false"}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="feePerKm"
                    header="Fee/Km (TL)"
                    sortable={(!showCreatePopup && !showUpdatePopup) ? "true" : "false"}
                  ></Column>
                  <Column
                    className={style.customColumn}
                    field="shortDistance"
                    header="Short Distance (TL)"
                    sortable={(!showCreatePopup && !showUpdatePopup) ? "true" : "false"}
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
      {showUpdatePopup && (
        <UpdatePopup
          onClose={closePopup}
          rowData={updateCity}
          accessToken={accessToken}
          style={style.popupStyle}
        />
      )}
      <div id="popup-create"></div>
      {showCreatePopup && (
        <CreatePopup
          onClose={closePopup}
          style={style.popupStyle}
        />
      )}
    </Fragment>
  )
};

export default TaxiFeeList;
