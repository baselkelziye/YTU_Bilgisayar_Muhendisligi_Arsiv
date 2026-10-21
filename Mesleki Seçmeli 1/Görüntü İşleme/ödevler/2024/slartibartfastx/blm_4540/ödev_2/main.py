import pickle
import numpy as np
import cv2

def unpickle(file):
    with open(file, 'rb') as fo:
        dict = pickle.load(fo, encoding='bytes')
    return dict

def getHue(b, g, r):
    r, g, b = r/255, g/255, b/255
    mx = max(r, g, b)
    mn = min(r, g, b)
    df = mx - mn
    if mx == mn:
        h = 0
    elif mx == r:
        h = (60 * ((g - b) / df) + 360) % 360
    elif mx == g:
        h = (60 * ((b - r) / df) + 120) % 360
    elif mx == b:
        h = (60 * ((r - g) / df) + 240) % 360
    h = int(h)
    return h
def calc_hsv(image):
    histogram = [0] * 360

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            b, g, r = image[i, j]
            hue_value = getHue(b, g, r)
            histogram[hue_value] += 1

    histogram_array = np.array(histogram)
    h_hist_normalized = histogram_array / np.sum(histogram_array)

    return h_hist_normalized

def calc_y(image):
    y_values = 0.299 * image[:, :, 0] + 0.587 * image[:, :, 1] + 0.114 * image[:, :,2]

    y_values = y_values.astype(np.uint8)

    histogram = [0] * 256


    for row in y_values:
        for y_value in row:

            histogram[int(y_value)] += 1

    # Normalize the histogram
    histogram_array = np.array(histogram)
    y_hist_normalized = histogram_array /np.sum(histogram_array)

    return y_hist_normalized

def calculate_train_histograms(filtered_train_images):
    y_histograms = []
    h_histograms = []

    for image in filtered_train_images:
        y_hist = calc_y(image)
        h_hist = calc_hsv(image)

        y_histograms.append(y_hist)
        h_histograms.append(h_hist)

    return np.array(y_histograms), np.array(h_histograms)

def euclidean_norm(A):
    return np.sqrt(np.sum(np.square(A)))

def cosine_method(A, B):
    # Flatten the arrays to ensure they are 1D
    A_flat = A.flatten()
    B_flat = B.flatten()

    dot_product = np.dot(A_flat, B_flat)
    norm_a = euclidean_norm(A_flat)
    norm_b = euclidean_norm(B_flat)
    return dot_product / (norm_a * norm_b)

def calc_similar(test_hist, train_hists):
    similarities = []

    for train_hist in train_hists:
        similarity = cosine_method(test_hist, train_hist)
        similarities.append(similarity)

    return np.array(similarities)
def selection_sort_desc(arr):
    # Create a copy of the array to hold the indices
    indices = list(range(len(arr)))

    # Selection sort algorithm
    for i in range(len(arr)):
        # Find the index of the maximum element in the remaining unsorted portion
        max_idx = i
        for j in range(i+1, len(arr)):
            if arr[indices[j]] > arr[indices[max_idx]]:
                max_idx = j

        # Swap the found maximum element with the first element
        indices[i], indices[max_idx] = indices[max_idx], indices[i]

    return indices

def get_top_three(arr):
    sorted_indices = selection_sort_desc(arr)
    return sorted_indices[:3]


def disp_image(image, label):
    global label_names

    image_label_name = label_names[label].decode('utf-8')
    print(f"Image Label: {label}, Label Name: {image_label_name}")
    print("--------------------------------------")

    h_image = np.zeros((image.shape[0], image.shape[1]), dtype=np.uint8)

    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            b, g, r = image[i, j]
            h = getHue(b, g, r)
            h_image[i, j] = int(h * 255 / 360)

    y_image = 0.299 * image[:, :, 2] + 0.587 * image[:, :, 1] + 0.114 * image[:, :, 0]
    y_image = y_image.astype(np.uint8)

    h_image_colored = cv2.cvtColor(h_image, cv2.COLOR_GRAY2BGR)
    y_image_colored = cv2.cvtColor(y_image, cv2.COLOR_GRAY2BGR)

    combined_image = np.hstack((image, h_image_colored, y_image_colored))

    window_name = f"Combined Image (Label: {label}, Label Name: {image_label_name})"
    cv2.imshow(window_name, combined_image)
    cv2.waitKey(0)

def hconcat_resize_min(im_list, interpolation=cv2.INTER_CUBIC):
    h_min = min(im.shape[0] for im in im_list)
    im_list_resized = [cv2.resize(im, (int(im.shape[1] * h_min / im.shape[0]), h_min), interpolation=interpolation) for im in im_list]
    return cv2.hconcat(im_list_resized)

def display_top_images(top_y_indices, top_h_indices):
    top_y_images = [filtered_train[idx] for idx in top_y_indices]
    top_h_images = [filtered_train[idx] for idx in top_h_indices]

    top_y_row = hconcat_resize_min(top_y_images)
    top_h_row = hconcat_resize_min(top_h_images)

    for i, idx in enumerate(top_y):
        label = filtered_train_labels[idx]
        label_name = label_names[label].decode('utf-8')
        print(
            f"Top {i + 1} Similar Image (Y Space, Label: {label}, Label Name: {label_name}, Similarity: {cosine_similarities_y[idx]:.4f})")
    for i, idx in enumerate(top_h):
        label = filtered_train_labels[idx]
        label_name = label_names[label].decode('utf-8')
        print(
            f"Top {i + 1} Similar Image (HSV Space, Label: {label}, Label Name: {label_name}, Similarity: {cosine_similarities_h[idx]:.4f})")

    combined_image = cv2.vconcat([top_y_row, top_h_row])

    cv2.imshow("Top Similar Images (Top: Y Space, Bottom: HSV Space)", combined_image)
    cv2.waitKey(0)

data_path = 'C:/Users/sefac/OneDrive/Masaüstü/cifar-10-batches-py/'

batch_filename = data_path + 'data_batch_5'
batch_data = unpickle(batch_filename)

images = batch_data[b'data']
labels = batch_data[b'labels']

images = images.reshape((len(images), 3, 32, 32)).transpose(0, 2, 3, 1)

meta_filename = data_path + 'batches.meta'
meta_data = unpickle(meta_filename)
label_names = meta_data[b'label_names']

target_labels = [2, 3, 4, 5, 6]

max_images_per_label_1 = 50
max_images_per_label_2 = 10

filtered_train = []
filtered_train_labels = []
filtered_test_images = []
filtered_test_labels = []


label_counter_1 = {label: 0 for label in target_labels}
label_counter_2 = {label: 0 for label in target_labels}

for i, label in enumerate(labels):
    if label in target_labels:
        if label_counter_1[label] < max_images_per_label_1:
            filtered_train.append(images[i])
            filtered_train_labels.append(label)
            label_counter_1[label] += 1
        elif label_counter_2[label] < max_images_per_label_2:
            filtered_test_images.append(images[i])
            filtered_test_labels.append(label)
            label_counter_2[label] += 1


y_histograms, h_histograms = calculate_train_histograms(filtered_train)


success_count_y = 0
success_count_h = 0
failure_count = 0

for idx_ in range(len(filtered_test_images)):
    test_y_hist = calc_y(filtered_test_images[idx_])
    test_h_hist = calc_hsv(filtered_test_images[idx_])

    cosine_similarities_y = calc_similar(test_y_hist, y_histograms)
    cosine_similarities_h = calc_similar(test_h_hist, h_histograms)

    disp_image(filtered_test_images[idx_], filtered_test_labels[idx_])
    top_y = get_top_three(cosine_similarities_y)
    top_h = get_top_three(cosine_similarities_h)
    print("Top Three Indices for Y Space:", top_y)
    print("Top Three Indices for HSV Space:", top_h)
    display_top_images(top_y, top_h)
    cv2.destroyAllWindows()

    result_y = "Failure"
    result_h = "Failure"

    for top_idx in top_y:
        if filtered_train_labels[top_idx] == filtered_test_labels[idx_]:
            success_count_y += 1
            result_y = "Success"
            break

    for top_idx in top_h:
        if filtered_train_labels[top_idx] == filtered_test_labels[idx_]:
            success_count_h += 1
            result_h = "Success"
            break

    if result_y == "Failure" and result_h == "Failure":
        failure_count += 1

    print(f"Test Image {idx_ + 1}: Y Channel {result_y}, H Channel {result_h}")

total_tests = len(filtered_test_images)
success_rate_y = (success_count_y / total_tests) * 100
success_rate_h = (success_count_h / total_tests) * 100
total_success = ( (total_tests-failure_count)/ total_tests)*100

print(f"\nY Histogram Success Rate: {success_rate_y:.2f}%")
print(f"H Histogram Success Rate: {success_rate_h:.2f}%")
print(f"Total Success Rate: {total_success:.2f}%")
