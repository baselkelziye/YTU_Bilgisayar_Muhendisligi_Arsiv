import Fee from "../../models/fee";
import FeeSchema from "./validations";
import Boom from "boom";

// helpers
import {
  signAccessToken,
  signRefreshToken,
  verifyRefreshToken,
} from "../../helpers/jwt";
import redis from "../../clients/redis";

const Create = async (req, res, next) => {
  const input = req.body;
  const { error } = FeeSchema.validate(input);

  if(error) {
    return next(Boom.badRequest(error.details[0].message));
  }

  const fee = new Fee(input);
  const savedData = await fee.save();

  res.json(savedData);
};

const Get = async (req, res, next) => {
  const { city } = req.params;

  if (!city) {
    return next(Boom.badRequest("Missing parameter (:city)!"));
  }

  try {
    const fee = await Fee.findOne({ city: city });

    res.json(fee);
  } catch (e) {
    next(e);
  }
};

const Update = async (req, res, next) => {
  const { city } = req.params;

  console.log(req.body);

  try {
    const updated = await Fee.findOneAndUpdate({city: city}, req.body, {
        new: true,
    });

    res.json(updated);
  } catch (e) {
    next(e);
  }
};

const Delete = async (req, res, next) => {
  const { city } = req.params;

  try {
    const deleted = await Fee.findOneAndDelete({city: city});

    if (!deleted) {
        throw Boom.badRequest("City not found!");
    }

    res.json(deleted);
  } catch(e) {
    next(e);
  }
};

// const limit = 10;
const GetList = async (req, res, next) => {
  // let { page } = req.query;

  // if (page < 1) {
  //   page = 1;
  // }

  const { city } = req.payload;

  // const skip = (parseInt(page) - 1) * limit;

  try {
    let feeList = null;

    feeList = await Fee.find({})
    .sort({city: 1})
    // .skip(skip)
    // .limit(limit);

    res.json(feeList);
  } catch (e) {
    next(e);
  }
};

const getCities = async (req, res, next) => {
	try {
	const { refresh_token } = req.body;
	if (!refresh_token) {
	  throw Boom.badRequest();
	}
  
	const user_id = await verifyRefreshToken(refresh_token);
	const data = await redis.get(user_id);
  
	if (!data) {
	  throw Boom.badRequest();
	}
  
	const cityList = await Fee.find({}).select("-password -__v");
  
	res.json(cityList);
	} catch (e) {
	  next(e);
	}
};

export default {
  Create,
  Get,
  Update,
  Delete,
  GetList,
  getCities
};