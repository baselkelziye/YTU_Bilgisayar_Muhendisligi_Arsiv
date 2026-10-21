import express from "express";
const router = express.Router();

import Plan from "../controllers/plan";

import grantAccess from "../middlewares/grantAccess";
import { verifyAccessToken } from "../helpers/jwt";

router.post(
	"/",
	verifyAccessToken,
	grantAccess("createAny", "plan"),
	Plan.Create
);
router.get(
	"/:plan_id",
	verifyAccessToken,
	grantAccess('readAny', 'plan'),
	Plan.Get
);
router.get(
	"/",
	verifyAccessToken,
	grantAccess("readAny", "plan"), 
	Plan.GetList
);
router.put(
	"/:plan_id", 
	verifyAccessToken,
	grantAccess("updateAny", "plan"),
	Plan.Update
);
router.delete(
	"/:plan_id",
	verifyAccessToken,
	grantAccess("deleteAny", "plan"), 
	Plan.Delete
);

export default router;
