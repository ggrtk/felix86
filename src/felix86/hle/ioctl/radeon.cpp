#include <asm/ioctl.h>
#include <sys/ioctl.h>
#include "felix86/common/log.hpp"
#include "felix86/hle/ioctl/common.hpp"
#include "felix86/hle/ioctl/radeon.hpp"

int ioctl32_radeon(int fd, u32 cmd, u32 args) {
    switch (_IOC_NR(cmd)) {
        MARSHAL_CASE(DRM_IOCTL_RADEON_CP_INIT, drm_radeon_init_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_CLEAR, drm_radeon_clear_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_STIPPLE, drm_radeon_stipple_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_TEXTURE, drm_radeon_texture_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_VERTEX2, drm_radeon_vertex2_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_CMDBUF, drm_radeon_cmd_buffer_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_GETPARAM, drm_radeon_getparam_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_ALLOC, drm_radeon_mem_alloc_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_IRQ_EMIT, drm_radeon_irq_emit_t);
        MARSHAL_CASE(DRM_IOCTL_RADEON_SETPARAM, drm_radeon_setparam_t);

        SIMPLE_CASE(DRM_IOCTL_RADEON_CP_START);
        SIMPLE_CASE(DRM_IOCTL_RADEON_CP_STOP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_CP_RESET);
        SIMPLE_CASE(DRM_IOCTL_RADEON_CP_IDLE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_RESET);
        SIMPLE_CASE(DRM_IOCTL_RADEON_FULLSCREEN);
        SIMPLE_CASE(DRM_IOCTL_RADEON_SWAP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_VERTEX);
        SIMPLE_CASE(DRM_IOCTL_RADEON_INDICES);
        SIMPLE_CASE(DRM_IOCTL_RADEON_INDIRECT);
        SIMPLE_CASE(DRM_IOCTL_RADEON_FLIP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_FREE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_INIT_HEAP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_IRQ_WAIT);
        SIMPLE_CASE(DRM_IOCTL_RADEON_CP_RESUME);
        SIMPLE_CASE(DRM_IOCTL_RADEON_SURF_ALLOC);
        SIMPLE_CASE(DRM_IOCTL_RADEON_SURF_FREE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_CREATE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_INFO);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_MMAP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_PREAD);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_PWRITE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_SET_DOMAIN);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_WAIT_IDLE);
        SIMPLE_CASE(DRM_IOCTL_RADEON_CS);
        SIMPLE_CASE(DRM_IOCTL_RADEON_INFO);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_SET_TILING);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_GET_TILING);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_BUSY);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_VA);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_OP);
        SIMPLE_CASE(DRM_IOCTL_RADEON_GEM_USERPTR);
    default: {
        ERROR("Unknown radeon ioctl cmd: %x", cmd);
        return -1;
    }
    }
}