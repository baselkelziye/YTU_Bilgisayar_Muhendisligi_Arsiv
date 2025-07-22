def calculate_top1_top5_scores(data: list, model_name: str) -> dict:
    """
    Verilen veri seti için top1 ve top5 doğruluk skorlarını hesaplar.

    Args:
        data (list): Veri seti
        model_name (str): Model adı

    Returns:

        dict: Model adı, top1 ve top5 doğruluk skorları
    """
    # Eğer bir sözlük ise listeye dönüştür
    if isinstance(data, dict):
        data = [data]
    
    total_entries = len(data)
    top1_correct = 0
    top5_correct = 0
    
    for item in data:
        # source_index ile 1st_index eşleşiyor mu kontrol et
        if item['source_index'] == item['1st_index']:
            top1_correct += 1
        
        # source_index top5_indexs içinde var mı kontrol et
        if item['source_index'] in item['top5_indexs']:
            top5_correct += 1
    
    # Skorları hesapla
    top1_score = top1_correct / total_entries if total_entries > 0 else 0
    top5_score = top5_correct / total_entries if total_entries > 0 else 0
    
    return {
        "model_name": model_name,
        "top1_score": top1_score,
        "top5_score": top5_score
    }