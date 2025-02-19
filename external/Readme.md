# External Files

This directory contains third-party dependencies and external libraries that are not part of the main project.

## Current Dependencies

- Catch2 (catch.hpp) - Header-only testing framework
  - Location: ${PROJECT_DIR}/external/catch.hpp
  - Version: 2.x
  - License: Boost Software License 1.0

## Adding New Dependencies

1. Document all new external dependencies in this README
2. Include version information and licensing details
3. Prefer Git submodules for dependencies that are actively maintained
4. For header-only libraries, include the minimal required files
5. Update CMakeLists.txt when adding new dependencies

## Guidelines

- Keep external dependencies to a minimum
- Regularly update dependencies for security and bug fixes
- Verify license compatibility with the project
- Document any modifications to external code
