import Plan from "../../models/plan";
import User from "../../models/user";
import Boom from "boom";
import PlanSchema from "./validations";

const Create = async (req, res, next) => {
  const input = req.body;
  const { error } = PlanSchema.validate(input);

  if (error) {
  	return next(Boom.badRequest(error.details[0].message));
  }

	const plan = new Plan(input);
	const savedData = await plan.save();

	res.json(savedData);
};

const Get = async (req, res, next) => {
  const { plan_id } = req.params;

  if (!plan_id) {
  	return next(Boom.badRequest("Missing parameter (:plan_id)!"));
  }

  try {
  	const plan = await Plan.findById(plan_id);

    res.json(plan);
  } catch (e) {
  	next(e);
  }
};

const Update = async (req, res, next) => {
  const { plan_id } = req.params;

  try {
  	const updated = await Plan.findByIdAndUpdate(plan_id, req.body, {
  		new: true,
  	});

  	res.json(updated);
  } catch (e) {
  	next(e);
  }
};

const Delete = async (req, res, next) => {
  const { plan_id } = req.params;

  try {
  	const deleted = await Plan.findByIdAndDelete(plan_id);

	if (!deleted) {
	  throw Boom.badRequest("Travel not found!");
	}

	res.json(deleted);
  } catch (e) {
  	next(e);
  }
};

// const limit = 10;
const GetList = async (req, res, next) => {
  let { page } = req.query;

  // if (page < 1) {
  // 	page = 1;
  // }

  const { user_id } = req.payload;
  
  let user = null;
  try {
  	user = await User.findById(user_id).select("-password -__v");
  } catch (e) {
	  next(e);
  }

  // const skip = (parseInt(page) - 1) * limit;

  try {
    let plans = null;
    
    if (user.role === "employee") {
        plans = await Plan.find({ employeeUsername: user.username })
  	  .sort({ createdAt: -1 })
  	  // .skip(skip)
  	  // .limit(limit);
    }
    else {
        plans = await Plan.find({})
  	  .sort({ createdAt: -1 })
  	  // .skip(skip)
  	  // .limit(limit);
    }

	  res.json(plans);
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
};
