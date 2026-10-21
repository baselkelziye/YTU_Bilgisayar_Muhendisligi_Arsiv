require 'csv'

class SingleNeuron
  attr_accessor :delta, :weights, :output

  def initialize(inputlen)
    create_weights(inputlen)
  end

  def create_weights(inputlen)
    @weights = []
    (inputlen + 1).times do
      @weights << (rand > 0.5 ? -rand : rand)
    end
  end

  def update_weight(inputs, training_rate)
    inputs << -1
    @weights.each_index do |i|
      @weights[i] +=  training_rate * delta * inputs[i]
    end
  end

  def get_weights
    @weights
  end

  def propagate(input)
    @output = activation_function(input)
  end

  def activation_function(input)
    sum = 0
    input.each_with_index do |n, index|
      sum +=  @weights[index] * n
    end
    sum += @weights.last * -1
    sigmoid_function(sum)
  end

  def sigmoid_function(x)
    1 / (1+Math.exp(-1 * (x)))
  end

  private :activation_function, :sigmoid_function, :create_weights
end

class SigmoidMLNN

  def initialize(options={})
    @input_size = options[:inputs]
    @hidden_layers = options[:hidden_layers]
    @number_of_output_nodes = options[:output_nodes]
    @number_of_neurons = options[:hidden_layer_neurons]
    setup_network
  end

  def feed_forward(input)
    @network.each_with_index do |layer, layer_index|
      layer.each do |neuron|
        if layer_index == 0
          neuron.propagate(input)
        else
          input = @network[layer_index-1].map {|x| x.output}
          neuron.propagate(input)
        end
      end
    end
    @network.last.map {|x| x.output}
  end

  def train(input, targets)
    feed_forward(input)
    compute_deltas(targets)
    update_weights(input)
    calculate_error(targets)
  end

  def get_network
    @network
  end

  def update_weights(input)
    reversed_network = @network.reverse
    reversed_network.each_with_index do |layer, layer_index|
      if layer_index == 0
        update_output_weights(layer, layer_index, input)
      else
        update_hidden_weights(layer, layer_index, input)
      end
    end
  end

  def update_output_weights(layer, layer_index, input)
    inputs = @hidden_layers.empty? ? input : @network[-2].map {|x| x.output}
    layer.each do |neuron|
      neuron.update_weight(inputs, 0.25)
    end
  end

  def update_hidden_weights(layer, layer_index, original_input)
    if layer_index == (@network.size - 1)
      inputs = original_input
    else
      inputs = @network.reverse[layer_index+1].map {|x| x.output}
    end
    layer.each_with_index do |neuron, index|
      neuron.update_weight(inputs, 0.25)
      p inputs.inspect
      p "Neuron#{index+1} weight" + neuron.get_weights.inspect
    end
  end

  def compute_deltas(targets)
    reversed_network = @network.reverse
    reversed_network.each_with_index do |layer, layer_index|
      if layer_index == 0
        compute_output_deltas(layer, targets)
      else
        compute_hidden_deltas(layer, targets)
      end
    end
  end

  def compute_output_deltas(layer, targets)
    layer.each_with_index do |neuron, i|
      output = neuron.output
      neuron.delta = output * (1 - output) * (targets[i] - output)
    end
  end

  def compute_hidden_deltas(layer, targets)
    layer.each_with_index do |neuron, neuron_index|
      error = 0
      @network.last.each do |output_neuron|
        error += output_neuron.delta * output_neuron.weights[neuron_index]
      end
      output = neuron.output
      neuron.delta = output * (1 - output) * error
    end
  end

  def calculate_error(targets)
    outputs = @network.last.map {|x| x.output}
    sum = 0
    targets.each_with_index do |t, index|
      sum += (t - outputs[index]) ** 2
    end
    0.5 * sum
  end

  def setup_network
    @network = []

    @hidden_layers.each_with_index do |number_of_neurons, index|
      layer = []
      puts "number_of_neurons " + @number_of_neurons.to_s
      inputs = index == 0 ? @input_size : @hidden_layers[index-1].size
      @number_of_neurons.times { layer << SingleNeuron.new(inputs) }
      @network << layer
    end

    inputs = @hidden_layers.empty? ? @input_size : @hidden_layers.last
    layer = []
    @number_of_output_nodes.times { layer << SingleNeuron.new(inputs)}
    @network << layer
  end

  private :update_weights, :update_output_weights, :update_hidden_weights, :compute_deltas,
  :compute_output_deltas, :compute_hidden_deltas, :calculate_error, :setup_network
end

class HardLimiter
  attr_accessor :threshold, :curr_weight

  def initialize(params = {})
    params.each do |key, value|
      self.instance_variable_set("@#{key}".to_sym, value)
    end
  end

  def acquire_class
    if @curr_weight[1..-1].to_f <= @threshold
      return "Class 0"
    else
      return "Class 1"
    end
  end
end

sigmoidmlnn = SigmoidMLNN.new(:hidden_layer_neurons => 2, :hidden_layers => [1], :output_nodes => 1, :inputs => 2)

puts "======== Train data ========"
1200.times do |i|
  CSV.foreach("veri2.csv", {:col_sep => ";"}) do |row|
    # p "row" + row.inspect
    err = sigmoidmlnn.train([row[0].to_f, row[1].to_f], [row[2].to_i])
    p err
  end
end

puts "======== Test data ========"
hl = HardLimiter.new(:threshold => 0.5, :curr_weight => sigmoidmlnn.feed_forward([3.00, 1.75]).inspect)
puts "V1 ~ 1 [3.00, 1.75] == #{sigmoidmlnn.feed_forward([3.00, 1.75]).inspect}"
puts hl.acquire_class
hl.curr_weight = sigmoidmlnn.feed_forward([4.25, 1.20]).inspect
puts "V2 ~ 0 [4.25, 1.20] == #{sigmoidmlnn.feed_forward([4.25, 1.20]).inspect}"
puts hl.acquire_class
hl.curr_weight = sigmoidmlnn.feed_forward([3.45, 1.70]).inspect
puts "V3 ~ 1 [3.45, 1.70] == #{sigmoidmlnn.feed_forward([3.45, 1.70]).inspect}"
puts hl.acquire_class
hl.curr_weight = sigmoidmlnn.feed_forward([1.20, 2.35]).inspect
puts "V4 ~ 0 [1.20, 2.35] == #{sigmoidmlnn.feed_forward([1.20, 2.35]).inspect}"
puts hl.acquire_class
hl.curr_weight = sigmoidmlnn.feed_forward([2.90, 2.00]).inspect
puts "V5 ~ 1 [2.90, 2.00] == #{sigmoidmlnn.feed_forward([2.90, 2.00]).inspect}"
puts hl.acquire_class

p sigmoidmlnn.inspect
