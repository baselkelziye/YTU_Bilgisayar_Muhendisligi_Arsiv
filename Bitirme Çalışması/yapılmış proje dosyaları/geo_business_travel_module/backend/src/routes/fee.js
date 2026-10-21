import express from "express";
const router = express.Router();

import Fee from "../controllers/fee";

import grantAccess from "../middlewares/grantAccess";
import { verifyAccessToken } from "../helpers/jwt";

router.post(
    "/",
    Fee.Create
);
router.get(
    "/:city",
    verifyAccessToken,
    grantAccess("readAny", "fee"),
    Fee.Get
);
router.get(
    "/",
    verifyAccessToken,
    grantAccess("readAny", "fee"),
    Fee.GetList
);
router.post(
    "/cities",
    verifyAccessToken,
    grantAccess("readAny", "fee"),
    Fee.getCities
);
router.put(
    "/:city",
    verifyAccessToken,
    grantAccess("updateAny", "fee"),
    Fee.Update
)
router.delete(
    "/:city",
    verifyAccessToken,
    grantAccess("deleteAny", "fee"),
    Fee.Delete
);

export default router;
