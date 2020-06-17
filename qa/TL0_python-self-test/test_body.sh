#!/bin/bash -e

test_nose() {
    for test_script in $(ls test_operator_*.py test_pipeline*.py test_functional_api.py test_backend_impl.py); do
        nosetests --verbose --attr '!slow' ${test_script}
    done
}

test_py() {
    python test_detection_pipeline.py -i 300
    python test_RN50_data_pipeline.py -i 10
    python test_coco_tfrecord.py -i 64
    python test_data_containers.py -s -b 20
    python test_data_containers.py -s -b 20 -n
}

test_no_fw() {
    test_nose
    test_py
}

test_cupy() {
    nosetests --verbose test_backend_impl_gpu.py
    # use this weird name to avoid being caught by test_operator_*.py
    nosetests --verbose test_gpu_operator_external_source.py
}


run_all() {
  test_no_fw
  test_cupy
}
