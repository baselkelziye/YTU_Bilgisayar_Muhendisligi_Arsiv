#!/bin/bash

set -e

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

print_usage() {
    echo "$0"
    echo "    Usage: $0 {spotify_churn_build, spotify_churn_eval, spotify_churn_all, customer_churn_build, customer_churn_eval, customer_churn_all}"
    echo "    Description: This script will generate the default results for you."
}

if [ $# -ne 1 ];
then
    print_usage
    exit 0
fi

choice="$1"

if [[ -z "$VIRTUAL_ENV" ]]; then
    if [[ -f "$SCRIPT_DIR/env/bin/activate" ]]; then
        source "$SCRIPT_DIR/env/bin/activate"
        echo "Activated venv at $VIRTUAL_ENV"
    else
        echo "Warning: No venv detected and no venv folder found at $SCRIPT_DIR/env"
    fi
fi

build_spotify_churn() {
    dataset="spotify_churn_dataset"
    csv="$SCRIPT_DIR/dataset/$dataset/$dataset.csv"
    testset="$SCRIPT_DIR/dataset/$dataset/default_testset.json"
    trainset="$SCRIPT_DIR/dataset/$dataset/default_trainset.json"

    if [[ ! -f "$testset" || ! -f "$trainset" ]]; then
        echo "Default trainset and testset files couldn't be found. Will create them..."
        $SCRIPT_DIR/main.py process_dataset -d "$csv" --trainset-outfile "$trainset" --testset-outfile "$testset"
    fi

    ### build ###
    echo "BUILDING DECISION TREE CLASSIFIER"
    $SCRIPT_DIR/main.py decision_tree build
    echo "BUILT DECISION TREE CLASSIFIER"
    echo ""

    echo "BUILDING CBA CLASSIFIER"
    $SCRIPT_DIR/main.py CBA generate
    echo "BUILT CBA CLASSIFIER"
    echo ""

    echo "BUILDING NAIVE BAYESIAN CLASSIFIER"
    $SCRIPT_DIR/main.py naive_bayesian build
    echo "BUILT NAIVE BAYESIAN CLASSIFIER"
    echo ""
}

eval_spotify_churn() {
    ### evaluate ###
    echo -e "EVALUATING DECISION TREE CLASSIFIER\n"
    $SCRIPT_DIR/main.py decision_tree evaluate
    echo "EVALUATED DECISION TREE CLASSIFIER"
    echo ""

    echo -e "EVALUATING CBA CLASSIFIER\n"
    $SCRIPT_DIR/main.py CBA evaluate
    echo "EVALUATED CBA CLASSIFIER"
    echo ""

    echo -e "EVALUATING NAIVE BAYESIAN CLASSIFIER\n"
    $SCRIPT_DIR/main.py naive_bayesian evaluate
    echo "EVALUATED NAIVE BAYESIAN CLASSIFIER"
    echo ""
}

build_customer_churn() {
    dataset="customer_churn_dataset"
    csv="$SCRIPT_DIR/dataset/$dataset/$dataset.csv"
    testset="$SCRIPT_DIR/dataset/$dataset/default_testset.json"
    trainset="$SCRIPT_DIR/dataset/$dataset/default_trainset.json"

    pickles="$SCRIPT_DIR/pickles/$dataset"
    dotfiles="$SCRIPT_DIR/dotfiles/$dataset"

    if [[ ! -f "$testset" || ! -f "$trainset" ]]; then
        echo "Default trainset and testset files couldn't be found. Will create them..."
        $SCRIPT_DIR/main.py process_dataset -d "$csv" --trainset-outfile "$trainset" --testset-outfile "$testset" --field-types $(cat "dataset/$dataset/${dataset}_field_types.txt") --label-idx 10
        echo ""
    fi

    ### build ###
    echo "BUILDING DECISION TREE CLASSIFIER"

    $SCRIPT_DIR/main.py decision_tree build \
        --trainset-infile "$trainset" \
        --pickle-path "$pickles/default_decision_tree.pickle" \
        --dot-outfile "$dotfiles/default_decision_tree.dot"

    echo "BUILT DECISION TREE CLASSIFIER"
    echo ""

    echo "BUILDING CBA CLASSIFIER"
    $SCRIPT_DIR/main.py CBA generate --trainset-infile "$trainset" --pickle-path "$pickles/default_rules.pickle"
    echo "BUILT CBA CLASSIFIER"
    echo ""

    echo "BUILDING NAIVE BAYESIAN CLASSIFIER"
    $SCRIPT_DIR/main.py naive_bayesian build --trainset-infile "$trainset" --pickle-path "$pickles/default_probability_table.pickle"
    echo "BUILT NAIVE BAYESIAN CLASSIFIER"
    echo ""
}

eval_customer_churn() {
    dataset="customer_churn_dataset"
    csv="$SCRIPT_DIR/dataset/$dataset/$dataset.csv"
    testset="$SCRIPT_DIR/dataset/$dataset/default_trainset.json"
    trainset="$SCRIPT_DIR/dataset/$dataset/default_trainset.json"

    pickles="$SCRIPT_DIR/pickles/$dataset"
    dotfiles="$SCRIPT_DIR/dotfiles/$dataset"

    ### evaluate ###
    echo -e "EVALUATING DECISION TREE CLASSIFIER\n"
    $SCRIPT_DIR/main.py decision_tree evaluate --testset-infile "$testset" --pickle-path "$pickles/default_decision_tree.pickle"
    echo "EVALUATED DECISION TREE CLASSIFIER"
    echo ""

    echo -e "EVALUATING CBA CLASSIFIER\n"
    $SCRIPT_DIR/main.py CBA evaluate --testset-infile "$testset" --pickle-path "$pickles/default_rules.pickle"
    echo "EVALUATED CBA CLASSIFIER"
    echo ""

    echo -e "EVALUATING NAIVE BAYESIAN CLASSIFIER\n"
    $SCRIPT_DIR/main.py naive_bayesian evaluate --testset-infile "$testset" --pickle-path "$pickles/default_probability_table.pickle"
    echo "EVALUATED NAIVE BAYESIAN CLASSIFIER"
    echo ""
}

if [[ $1 == "spotify_churn_build" ]]; then
    build_spotify_churn

elif [[ $1 == "spotify_churn_eval" ]]; then
    eval_spotify_churn

elif [[ $1 == "spotify_churn_all" ]]; then
    build_spotify_churn
    eval_spotify_churn

elif [[ $1 == "customer_churn_build" ]]; then
    build_customer_churn

elif [[ $1 == "customer_churn_eval" ]]; then
    eval_customer_churn

elif [[ $1 == "customer_churn_all" ]]; then
    build_customer_churn
    eval_customer_churn

else
    print_usage

fi

