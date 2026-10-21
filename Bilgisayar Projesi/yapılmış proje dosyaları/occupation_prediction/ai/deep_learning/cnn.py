from keras.layers import Embedding, Conv1D, Dense, Dropout, Flatten, GlobalMaxPooling1D
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from tensorflow import keras

from ai.utils import load_data, convert_labels_to_numerical, get_prediction_results, create_bow_vector

if __name__ == '__main__':
    # Load data
    data, labels = load_data("data", group=True, group_size=2, unique=True)

    # Split data into train and test sets
    train_data, test_data, train_labels, test_labels = train_test_split(data, labels, test_size=0.3, random_state=42)

    # Convert labels to numerical form
    labels_dict = sorted(list(dict.fromkeys(train_labels)))
    label_mapping = {label: i for i, label in enumerate(labels_dict)}
    train_labels = convert_labels_to_numerical(train_labels, label_mapping)
    test_labels = convert_labels_to_numerical(test_labels, label_mapping)

    # Create vectorizer
    n = 1
    vectorizer = TfidfVectorizer(ngram_range=(n, n))
    vectorizer.fit(train_data)

    VOCABULARY_SIZE = len(set(vectorizer.vocabulary_))
    MAX_LENGTH = max(len(max(train_data, key=len).split()), len(max(test_data, key=len).split()))

    print('vocabulary size:', VOCABULARY_SIZE)
    print('max length:', MAX_LENGTH)

    # Create bag-of-words vectors
    train_vectors = create_bow_vector(vectorizer, train_data, input_length=MAX_LENGTH)
    test_vectors = create_bow_vector(vectorizer, test_data, input_length=MAX_LENGTH)

    # Create the model
    model = keras.Sequential()
    model.add(keras.layers.Input(shape=(train_vectors.shape[1],)))
    model.add(Embedding(input_dim=VOCABULARY_SIZE, output_dim=train_vectors.shape[1], trainable=True))

    model.add(Conv1D(filters=128, kernel_size=3, activation='relu'))
    model.add(GlobalMaxPooling1D())
    model.add(Dropout(0.5))

    model.add(Flatten())
    model.add(Dense(units=10, activation='softmax'))

    # Compile the model
    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

    # Print model summary
    model.summary()

    # Train the model
    model.fit(train_vectors, train_labels, epochs=10, batch_size=64, validation_split=0.1, shuffle=True,
              callbacks=[keras.callbacks.EarlyStopping(monitor='val_loss', patience=2, restore_best_weights=True)])

    # Make predictions and print results
    accuracy, report, cm = get_prediction_results(model, test_vectors, test_labels, label_mapping)

    print("\nConfusion Matrix:\n", cm)
    print("\nClassification Report:\n", report)
    print(f"Accuracy: {accuracy}")
