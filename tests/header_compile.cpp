#include "gpulite/gpulite.hpp"

int main() {
    // Force instantiation of the runtime type aliases used by the public API.
    static_assert(sizeof(cudaError_t) > 0);
    static_assert(sizeof(cudaStream_t) > 0);
    static_assert(sizeof(cudaPointerAttributes) > 0);
    return gpulite::CUDART::loaded() ? 0 : 0;
}
