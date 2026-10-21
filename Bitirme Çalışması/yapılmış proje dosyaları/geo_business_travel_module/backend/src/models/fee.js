import mongoose from "mongoose";

const Schema = mongoose.Schema;

const FeeSchema = new Schema({
  city: {
    type: String,
    required: true,
    unique: true,
  },
  openingFee: {
    type: Number,
    required: true,
  },
  feePerKm: {
    type: Number,
    required: true,
  },
  shortDistance: {
    type: Number,
    required: true,
  }
});

const Fee = mongoose.model("taxi_fare_list", FeeSchema);

export default Fee;