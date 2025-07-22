from typing import Dict, Tuple, List, TYPE_CHECKING
import json
import os
import pandas as pd
from transformers import AutoModel, AutoTokenizer
if TYPE_CHECKING:
    import numpy as np

file_dir = os.path.dirname(os.path.abspath(__file__))
similarity_results_dir = os.path.join(file_dir, "similarity_results")
top1_top5_results_dir = os.path.join(file_dir, "top1_top5_results")
embeddings_dir = os.path.join(file_dir, "embeddings")
tsne_save_dir = os.path.join(file_dir, "tsne_results")
probabilities_dir = os.path.join(file_dir, "probabilities")
def tr_to_lower(text: str) -> str:
    """
    Verilen metni Türkçe karakterleri doğru şekilde koruyarak küçük harfe çeviren fonksiyon.
    """
    # Türkçe büyük karakterlerin küçük karşılıkları
    tr_map = {
        'İ': 'i',
        'I': 'ı',
        'Ğ': 'ğ',
        'Ü': 'ü',
        'Ö': 'ö',
        'Ş': 'ş',
        'Ç': 'ç'
    }
    
    # Önce Türkçe karakterleri dönüştür
    for upper, lower in tr_map.items():
        text = text.replace(upper, lower)
    
    # Sonra normal küçültme işlemini yap
    return text.lower()
def get_result_infix(is_question_to_answer: bool) -> str:
    """
    Sonuç dosyalarının adında kullanılacak ek getiren fonksiyon.

    Args:
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu
    
    Returns:
        str: Sonuç dosyalarının adında kullanılacak ek
    """
    return "question_to_answer" if is_question_to_answer else "answer_to_question"
def get_top1_top5_result_file_name(prefix: str, is_question_to_answer: bool) -> str:
    """
    Top1 ve top5 sonuçlarının kaydedileceği JSON dosyasının adını döndüren fonksiyon.

    Args:
        prefix: Model adının yer aldığı dosya adı öneki
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu

    Returns:
        str: JSON dosyasının adı
    """
    return f"{prefix}_{get_result_infix(is_question_to_answer)}_top1_top5_results.json"
def get_top1_top5_results_file_path(prefix: str, is_question_to_answer: bool) -> str:
    """
    Top1 ve top5 sonuçlarının kaydedileceği JSON dosyasının yolunu döndüren fonksiyon.

    Args:
        prefix: Model adının yer aldığı dosya adı öneki
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu

    Returns:
        str: JSON dosyasının yolu
    """
    file_name = get_top1_top5_result_file_name(prefix, is_question_to_answer)
    return os.path.join(top1_top5_results_dir, file_name)
def get_calculated_top5_results_size(prefix: str, is_question_to_answer: bool) -> int:
    """
    prefix'e göre kaydedilen top1 ve top5 sonuçlarının sayısını döndüren fonksiyon.

    Args:
        prefix: Kaydedilecek dosya adının öneki
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu

    Returns:
        int: Dosyada şimdiye kadar kaç top1 ve top5 sonucu kaydedildiği
    """
    file_path = get_top1_top5_results_file_path(prefix, is_question_to_answer)
    return get_json_size(file_path)
def append_top1_top5_results_json(prefix: str, is_question_to_answer: bool, top1_top5_results: Dict):
    """
    Top1 ve top5 sonuçlarını JSON formatında kaydeden fonksiyon.

    Args:
        prefix: Model adının yer aldığı dosya adı öneki
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu
        top1_top5_results: Kaydedilecek top1 ve top5 sonuçları
    """    
    # Dosya yolunu al
    file_path = get_top1_top5_results_file_path(prefix, is_question_to_answer)
    
    append_json(file_path, top1_top5_results)
def get_all_top1_top5_results() -> List[Dict]:
    """
    Tüm top1 ve top5 sonuçlarını okuyan fonksiyon.
    
    Returns:
        Dict: Okunan JSON verisi
    """
    all_results = []
    for file_name in os.listdir(top1_top5_results_dir):
        if file_name.endswith(".json"):
            with open(os.path.join(top1_top5_results_dir, file_name), 'r') as f:
                data = json.load(f)
                all_results.append(data)
    return all_results
def get_probabilities_dir(prefix: str) -> str:
    """
    Modelin olasılıklarını kaydedileceği dizini döndüren fonksiyon.
    
    Args:
        prefix: Model adının yer aldığı dosya adı öneki
    
    Returns:
        str: Olasılıkların kaydedileceği dizin
    """
    return os.path.join(probabilities_dir, f"{prefix}_probabilities.json")

def get_calculated_probabilities_size(prefix: str) -> int:
    """
    prefix'e göre kaydedilen olasılık vektörlerinin sayısını döndüren fonksiyon.
    
    Args:
        prefix: Kaydedilecek dosya adının öneki
    
    Returns:
        int: Dosyada şimdiye kadar kaç olasılık vektörü kaydedildiği
    """
    file_path = get_probabilities_dir(prefix)
    return get_json_size(file_path)

def append_probability(prefix: str, source: int, target: int, probability: float,
                       source_dest_type: str = "question_to_answer"):
    """
    Bir olasılık vektörünü ve ilgili veriyi JSON formatında dosyaya ekleyen fonksiyon.
    Her bir olasılık vektörü yeni bir satırda kaydedilir.
    
    Args:
        prefix: Kaydedilecek dosya adının öneki
        source: Kaynak verinin indeksi
        target: Hedef verinin indeksi
        probability: İki veri arasındaki olasılık
        source_dest_type: Kaynak ve hedef veri türü (soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu)
    """
    # Dosya yolu
    file_path = get_probabilities_dir(prefix)

    # JSON objesi oluştur
    json_object = {
        "source": source,
        "target": target,
        "probability": probability,
        "source_dest_type": source_dest_type
    }

    # Dosyayı aç ve yeni girişi ekle
    append_json(file_path, json_object)

def append_json(file_path, json_object):
    # Dosya yolunun var olup olmadığını kontrol et
    if not os.path.exists(os.path.dirname(file_path)):
        os.makedirs(os.path.dirname(file_path), exist_ok=True)
    
    file_exists = os.path.exists(file_path) and os.path.getsize(file_path) > 0
    with open(file_path, 'a' if file_exists else 'w', encoding='utf-8') as f:
        # JSON nesnesini ve bir virgülü tek bir satıra yaz
        f.write(json.dumps(json_object, ensure_ascii=False))
        f.write(',\n')
def read_probability_from_file(prefix: str) -> list:
    """
    JSON formatında kaydedilmiş olasılık vektörlerini ve ilgili verileri okuyan fonksiyon.
    
    Args:
        prefix: Kaydedilen dosya adının öneki

    Returns:
        list: Soru, cevap ve olasılık vektörleri içeren nesnelerin listesi
    """
    # Dosya yolu
    file_path = get_probabilities_dir(prefix)
    
    probabilities = read_jsonlist_from_file(file_path)
    
    print(f"{os.path.basename(file_path)} dosyasından {len(probabilities)} olasılık vektörü yüklendi.")
    return probabilities
def read_top1_top5_results_json(prefix: str, is_question_to_answer: bool) -> Dict:
    """
    JSON dosyasından top1 ve top5 sonuçlarını okuyan fonksiyon.
    
    Args:
        prefix: Model adının yer aldığı dosya adı öneki
        is_question_to_answer: Soru-cevap benzerliği mi yoksa cevap-soru benzerliği mi olduğu
    
    Returns:
        Dict: Okunan JSON verisi
    """
    file_path = get_top1_top5_results_file_path(prefix, is_question_to_answer)
    return read_jsonlist_from_file(file_path)


def load_model(model_name: str, device_type: str = "cuda") -> Tuple[AutoModel, AutoTokenizer]:
    """
    Hugging Face model ve tokenizer yükleyen fonksiyon.

    Args:
        model_name: Hugging Face model adı
        device_type: Kullanılacak cihaz (cuda ya da cpu)

    Returns:
        model: Yüklenen model
        tokenizer: Yüklenen tokenizer
    """
    print(f"Model yükleniyor: {model_name}", end="\r")
    tokenizer = AutoTokenizer.from_pretrained(model_name, trust_remote_code=True)
    model = AutoModel.from_pretrained(model_name, trust_remote_code=True).to(device_type)
    print(f"Model yüklendi. {model_name}", end="\r")
    return model, tokenizer


def load_dataset() -> pd.DataFrame:
    """
    Veri kümesini yükleyen fonksiyon.

    Returns:
        df: Yüklenen veri kümesi
    """ 
    # kod dosya yolu
    current_dir = os.path.dirname(os.path.abspath(__file__))
    
    # veri kümesi dosya yolu
    dataset_path = os.path.join(current_dir, '..', "gsm8k_tr_1000_soru_cevap.csv")
    
    # Veri kümesini yükle
    print(f"Veri kümesi yükleniyor: {dataset_path}")
    df = pd.read_csv(dataset_path)
    
    # tüm karakterleri küçült
    df['question'] = df['question'].apply(tr_to_lower)
    df['answer'] = df['answer'].apply(tr_to_lower)
    df["index"] = range(0, len(df))  # 1'den başlayarak her satıra sırayla numara ver
    return df

def get_embeddings_path(save_prefix: str) -> str:
    """
    Gömme vektörlerinin kaydedileceği dosya yolunu döndüren fonksiyon.

    Args:
        save_prefix: Kaydedilecek dosya adının öneki

    Returns:
        str: Gömme vektörlerinin kaydedileceği dosya yolu
    """
    return os.path.join(embeddings_dir, f"{save_prefix}_embeddings.json")

def get_json_size(file_path: str) -> int:
    """
    JSON dosyasındaki satır sayısını döndüren fonksiyon.

    Args:
        file_path: Dosya yolu

    Returns:
        int: Dosyadaki satır sayısı
    """
    if not os.path.exists(file_path):
        return 0
    return sum(1 for line in open(file_path))

def get_calculated_embeddings_size(save_prefix: str) -> int:
    """
    save_prefix'e göre kaydedilen gömme vektörlerinin sayısını döndüren fonksiyon.

    Args:
        save_prefix: Kaydedilecek dosya adının öneki

    Returns:
        int: dosyada şimdiye kadar kaç gömme vektörü kaydedildiği
    """
    file_path = get_embeddings_path(save_prefix)
    return get_json_size(file_path)

def append_embedding(save_prefix: str, item: pd.Series, question_embedding: 'np.ndarray', answer_embedding: 'np.ndarray'):
    """
    Bir gömme vektörünü ve ilgili veriyi JSON formatında dosyaya ekleyen fonksiyon.
    Her bir gömme yeni bir satırda kaydedilir.
    
    Args:
        save_prefix: Kaydedilecek dosya adının öneki
        item: Kaydedilecek pandas Series nesnesi (soru ve cevap içeren)
        question_embedding: Soru gömme vektörü
        answer_embedding: Cevap gömme vektörü
    """
        
    # Get the file path with json extension
    json_path = get_embeddings_path(save_prefix)
    
    # Create a JSON object with question, answer and embedding
    json_object = {
        "index": int(item["index"]),
        "question": item["question"],
        "answer": item["answer"],
        "question_embedding": question_embedding.tolist(),
        "answer_embedding": answer_embedding.tolist()
    }
    
    append_json(json_path, json_object)

def read_jsonlist_from_file(file_path: str) -> list:
    """
    JSON formatında kaydedilmiş bir dosyadaki tüm nesneleri okuyan fonksiyon.
    
    Args:
        file_path: Okunacak dosyanın yolu
    
    Returns:
        list: Okunan JSON nesneleri
    """
    # Check if file exists
    if not os.path.exists(file_path):
        print(f"Dosya bulunamadı: {file_path}")
        return []
    
    json_list = []
    # tüm kayıtları oku
    with open(file_path, 'r', encoding='utf-8') as f:
        line_num = 0
        for line in f:
            line_num += 1
            # Boş satırları atla
            line = line.strip()
            if not line:
                continue
                
            # Sondaki virgülü kaldır
            if line.endswith(','):
                line = line[:-1]
                
            # JSON nesnesini ayrıştır
            try:
                json_obj = json.loads(line)
                json_list.append(json_obj)
            except json.JSONDecodeError as e:
                print(f"Satır {line_num} işlenemedi: {e}")
                continue
    return json_list

def read_embedding_from_file(save_prefix: str) -> list:
    """
    JSON formatında kaydedilmiş gömme vektörlerini ve ilgili verileri okuyan fonksiyon.
    
    Args:
        save_prefix: Kaydedilen dosya adının öneki
        
    Returns:
        list: Soru, cevap ve gömme vektörleri içeren nesnelerin listesi
    """
    
    # Get the file path
    json_path = get_embeddings_path(save_prefix)
    
    # Check if file exists
    if not os.path.exists(json_path):
        print(f"Dosya bulunamadı: {json_path}")
        return []
    
    # Read all embeddings
    embeddings = []
    with open(json_path, 'r', encoding='utf-8') as f:
        line_num = 0
        for line in f:
            line_num += 1
            # Boş satırları atla
            line = line.strip()
            if not line:
                continue
                
            # Sondaki virgülü kaldır
            if line.endswith(','):
                line = line[:-1]
                
            # JSON nesnesini ayrıştır
            try:
                embedding_obj = json.loads(line)
                
                # Gömme listesini numpy dizisine dönüştür
                if isinstance(embedding_obj.get('embedding'), list):
                    embedding_obj['embedding'] = np.array(embedding_obj['embedding'])
                    
                embeddings.append(embedding_obj)
            except json.JSONDecodeError as e:
                print(f"Satır {line_num} işlenemedi: {e}")
                continue
    
    print(f"{os.path.basename(json_path)} dosyasından {len(embeddings)} gömme vektörü yüklendi.")
    return embeddings

def get_tsne_file_path(prefix: str) -> str:
    """
    t-SNE sonuçlarının kaydedileceği dosya adını döndüren fonksiyon.
    
    Args:
        prefix: Kaydedilecek dosya adının öneki
    
    Returns:

        str: t-SNE sonuçlarının kaydedileceği dosya adı
    """
    return os.path.join(tsne_save_dir, f"{prefix}_tsne_results.json")
def get_tsne_photo_path(prefix: str) -> str:
    """
    t-SNE sonuçlarının kaydedileceği dosya adını döndüren fonksiyon.
    
    Args:
        prefix: Kaydedilecek dosya adının öneki

    Returns:
    
        str: t-SNE sonuçlarının kaydedileceği dosya adı
    """
    return os.path.join(tsne_save_dir, f"{prefix}_tsne_results.png")

def get_example_tsne_photo_path(prefix: str) -> str:
    """
    Örnek t-SNE sonuçlarının kaydedileceği dosya adını döndüren fonksiyon.
    
    Args:
        prefix: Kaydedilecek dosya adının öneki

    Returns:

        str: t-SNE sonuçlarının kaydedileceği dosya adı
    """
    return os.path.join(tsne_save_dir, "ornekler", f"{prefix}_tsne_results.png")

def save_tsne_json(data: Dict, save_prefix: str):
    """
    t-SNE sonuçlarını JSON formatında kaydeden fonksiyon.
    
    Args:
        data: Kaydedilecek t-SNE sonuçları
        save_prefix: Kaydedilecek dosya adının öneki
    """
    # Create directory if it doesn't exist
    if not os.path.exists(tsne_save_dir):
        os.makedirs(tsne_save_dir)
    
    # Get the file path with json extension
    json_path = get_tsne_file_path(save_prefix)
    
    # Write the data to the file
    with open(json_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=4)