import express from "express";
const router = express.Router();

import Travel from "../controllers/travel";
// import cache from '../cache';

import grantAccess from "../middlewares/grantAccess";
import { verifyAccessToken } from "../helpers/jwt";

router.post(
	"/",
	verifyAccessToken,
	grantAccess("createAny", "travel"),
	Travel.Create
);
router.get(
	"/:travel_id",
	verifyAccessToken,
	grantAccess('readAny', 'travel'),
	// cache.route(),
	Travel.Get
);
// router.get('/', cache.route(), Product.GetList);
router.get(
	"/",
	verifyAccessToken,
	grantAccess("readAny", "travel"), 
	Travel.GetList
);
router.put(
	"/:travel_id", 
	verifyAccessToken,
	grantAccess("updateAny", "travel"),
	Travel.Update
);
router.delete(
	"/:travel_id",
	verifyAccessToken,
	grantAccess("deleteAny", "travel"), 
	Travel.Delete
);

export default router;
