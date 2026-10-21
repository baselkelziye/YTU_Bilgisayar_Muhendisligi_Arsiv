import Travel from "../../models/travel";
import User from "../../models/user";
import Boom from "boom";
import TravelSchema from "./validations";

const Create = async (req, res, next) => {
  const input = req.body;
  const { error } = TravelSchema.validate(input);

  if (error) {
  	return next(Boom.badRequest(error.details[0].message));
  }

  // TravelId ==> MongoDB Id
  // try {
  // 	let isTravelIdExists = true;
  // 	while(isTravelIdExists) {
  // 	  isTravelIdExists = await Travel.findOne({ travelId : input.travelId });

  //     if (isTravelIdExists) {
  //     	input.travelId++;
  //     }
	// }

	// input.photo = JSON.parse(input.photo);

	const travel = new Travel(input);
	const savedData = await travel.save();

	res.json("saved");
  // } catch (e) {
	// next(e);
  // }
};

const Get = async (req, res, next) => {
  const { travel_id } = req.params;

  if (!travel_id) {
  	return next(Boom.badRequest("Missing parameter (:travel_id)!"));
  }

  try {
  	const travel = await Travel.findById(travel_id);

    const { user_id } = req.payload;
  
    let user = null;
    try {
    	user = await User.findById(user_id).select("-password -__v");
    } catch (e) {
	    next(e);
    }

    if (user.role !== "employee" || user.username === travel.employeeUsername) {
      res.json(travel);
    }
    else {
      res.json({ message: "This record does not belong to you!" })
    }  
  } catch (e) {
  	next(e);
  }
};

const Update = async (req, res, next) => {
  const { travel_id } = req.params;

  console.log(req.body);

  try {
  	const updated = await Travel.findByIdAndUpdate(travel_id, req.body, {
  		new: true,
  	});

  	res.json(updated);
  } catch (e) {
  	next(e);
  }
};

const Delete = async (req, res, next) => {
  const { travel_id } = req.params;

  try {
  	const deleted = await Travel.findByIdAndDelete(travel_id);

	if (!deleted) {
	  throw Boom.badRequest("Travel not found!");
	}

	res.json(deleted);
  } catch (e) {
  	next(e);
  }
};

//const limit = 10;
const GetList = async (req, res, next) => {
  // let { page } = req.query;

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

  //const skip = (parseInt(page) - 1) * limit;

  try {
    let travels = null;
    
    if (user.role === "employee") {
      travels = await Travel.find({ employeeUsername: user.username })
  	  .sort({ createdAt: -1 })
  	  //.skip(skip)
  	  //.limit(limit);
    }
    else {
      travels = await Travel.find({})
  	  .sort({ createdAt: -1 })
  	  //.skip(skip)
  	  //.limit(limit);
    }

	  res.json(travels);
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
