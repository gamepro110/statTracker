# documentation config

set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_MAN NO)

set(DOXYGEN_EXCLUDE_PATTERNS "${DOXYGEN_EXCLUDE_PATTERNS} */tests/*" "*/vendor/*" "*/out/*")
set(DOXYGEN_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/docsBuild/")

doxygen_add_docs(
    Docs
    ${PROJECT_SOURCE_DIR}
    COMMENT "Generating HTML pages"
)

set_target_properties(
    Docs
    PROPERTIES
    FOLDER "StatTracker"
)
