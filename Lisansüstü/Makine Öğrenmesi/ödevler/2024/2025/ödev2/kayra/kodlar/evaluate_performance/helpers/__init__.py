"""
Evaluate Performance Helpers Package
=====================================
Bu paket, performans değerlendirme işlemleri için yardımcı modülleri içerir.
"""

from .data_loader import (
    get_dataset_path,
    load_dataset,
    split_train_test,
    get_all_datasets,
    split_features_target
)

from .model_trainer import (
    create_logistic_regression_model,
    cross_validate_model,
    detect_overfitting,
    apply_regularization,
    train_final_model,
    find_best_regularization
)

from .evaluation_metrics import (
    calculate_accuracy,
    calculate_f1_score,
    calculate_metrics,
    create_confusion_matrix,
    get_classification_report
)

from .report_generator import (
    generate_results_table,
    save_results_to_csv,
    generate_markdown_report,
    plot_confusion_matrix,
    save_confusion_matrix_plot,
    get_results_dir
)

__all__ = [
    # data_loader
    'get_dataset_path',
    'load_dataset',
    'split_train_test',
    'get_all_datasets',
    'split_features_target',
    
    # model_trainer
    'create_logistic_regression_model',
    'cross_validate_model',
    'detect_overfitting',
    'apply_regularization',
    'train_final_model',
    'find_best_regularization',
    
    # evaluation_metrics
    'calculate_accuracy',
    'calculate_f1_score',
    'calculate_metrics',
    'create_confusion_matrix',
    'get_classification_report',
    
    # report_generator
    'generate_results_table',
    'save_results_to_csv',
    'generate_markdown_report',
    'plot_confusion_matrix',
    'save_confusion_matrix_plot',
    'get_results_dir'
]
