#include <sys/ioctl.h>
#include "felix86/common/log.hpp"
#include "felix86/hle/ioctl/common.hpp"
#include "felix86/hle/ioctl/drm.hpp"
#include "felix86/hle/ioctl32.hpp"

int ioctl32_drm(int fd, u32 cmd, u32 args) {
    switch (_IOC_NR(cmd)) {
    case _IOC_NR(DRM_IOCTL_VERSION): {
        x86_drm_version* guest = (x86_drm_version*)(u64)args;
        drm_version host = *guest;
        int result = ::ioctl(fd, DRM_IOCTL_VERSION, &host);
        if (result != -1) {
            *guest = host;
            if (host.name && host.name_len) {
                std::string name(host.name, host.name_len);
                Ioctl32::registerFd(fd, name);
            }
        }
        return result;
    }

    case _IOC_NR(DRM_IOCTL_WAIT_VBLANK): {
        x86_drm_wait_vblank* guest = (x86_drm_wait_vblank*)(u64)args;
        drm_wait_vblank host;
        host.request = guest->request;
        int result = ::ioctl(fd, DRM_IOCTL_WAIT_VBLANK, &host);
        if (result != -1) {
            guest->reply = host.reply;
        }
        return result;
    }

        MARSHAL_CASE(DRM_IOCTL_GET_UNIQUE, drm_unique);
        MARSHAL_CASE(DRM_IOCTL_GET_MAP, drm_map);
        MARSHAL_CASE(DRM_IOCTL_GET_CLIENT, drm_client);
        MARSHAL_CASE(DRM_IOCTL_GET_STATS, drm_stats);
        MARSHAL_CASE(DRM_IOCTL_SET_UNIQUE, drm_unique);
        MARSHAL_CASE(DRM_IOCTL_ADD_MAP, drm_map);
        MARSHAL_CASE(DRM_IOCTL_ADD_BUFS, drm_buf_desc);
        MARSHAL_CASE(DRM_IOCTL_MARK_BUFS, drm_buf_desc);
        MARSHAL_CASE(DRM_IOCTL_INFO_BUFS, drm_buf_info);
        MARSHAL_CASE(DRM_IOCTL_FREE_BUFS, drm_buf_free);
        MARSHAL_CASE(DRM_IOCTL_RM_MAP, drm_map);
        MARSHAL_CASE(DRM_IOCTL_SET_SAREA_CTX, drm_ctx_priv_map);
        MARSHAL_CASE(DRM_IOCTL_GET_SAREA_CTX, drm_ctx_priv_map);
        MARSHAL_CASE(DRM_IOCTL_RES_CTX, drm_ctx_res);
        MARSHAL_CASE(DRM_IOCTL_DMA, drm_dma);
        MARSHAL_CASE(DRM_IOCTL_SG_ALLOC, drm_scatter_gather);
        MARSHAL_CASE(DRM_IOCTL_SG_FREE, drm_scatter_gather);
        MARSHAL_CASE(DRM_IOCTL_UPDATE_DRAW, drm_update_draw);
        MARSHAL_CASE(DRM_IOCTL_MODE_ADDFB2, drm_mode_fb_cmd2);
        MARSHAL_CASE(DRM_IOCTL_MODE_GETFB2, drm_mode_fb_cmd2);

    case DRM_IOCTL_MAP_BUFS: {
        WARN_ONCE("Running DRM_IOCTL_MAP_BUFS in 32-bit mode, this may allocate memory in high bits");
        x86_drm_buf_map* guest = (x86_drm_buf_map*)(u64)args;
        drm_buf_map host = *guest;
        int result = ::ioctl(fd, DRM_IOCTL_MAP_BUFS, &host);
        if (result != -1) {
            *guest = host;
        } else {
            result = -errno;
            VERBOSE("%s failed with %d", "DRM_IOCTL_MAP_BUFS", result);
        }
        return result;
    }

        SIMPLE_CASE(DRM_IOCTL_GET_MAGIC);
        SIMPLE_CASE(DRM_IOCTL_IRQ_BUSID);
        SIMPLE_CASE(DRM_IOCTL_SET_VERSION);
        SIMPLE_CASE(DRM_IOCTL_MODESET_CTL);
        SIMPLE_CASE(DRM_IOCTL_GEM_CLOSE);
        SIMPLE_CASE(DRM_IOCTL_GEM_FLINK);
        SIMPLE_CASE(DRM_IOCTL_GEM_OPEN);
        SIMPLE_CASE(DRM_IOCTL_GET_CAP);
        SIMPLE_CASE(DRM_IOCTL_SET_CLIENT_CAP);
        SIMPLE_CASE(DRM_IOCTL_AUTH_MAGIC);
        SIMPLE_CASE(DRM_IOCTL_BLOCK);
        SIMPLE_CASE(DRM_IOCTL_UNBLOCK);
        SIMPLE_CASE(DRM_IOCTL_CONTROL);
        SIMPLE_CASE(DRM_IOCTL_SET_MASTER);
        SIMPLE_CASE(DRM_IOCTL_DROP_MASTER);
        SIMPLE_CASE(DRM_IOCTL_ADD_CTX);
        SIMPLE_CASE(DRM_IOCTL_RM_CTX);
        SIMPLE_CASE(DRM_IOCTL_MOD_CTX);
        SIMPLE_CASE(DRM_IOCTL_GET_CTX);
        SIMPLE_CASE(DRM_IOCTL_SWITCH_CTX);
        SIMPLE_CASE(DRM_IOCTL_NEW_CTX);
        SIMPLE_CASE(DRM_IOCTL_ADD_DRAW);
        SIMPLE_CASE(DRM_IOCTL_RM_DRAW);
        SIMPLE_CASE(DRM_IOCTL_LOCK);
        SIMPLE_CASE(DRM_IOCTL_UNLOCK);
        SIMPLE_CASE(DRM_IOCTL_FINISH);
        SIMPLE_CASE(DRM_IOCTL_PRIME_HANDLE_TO_FD);
        SIMPLE_CASE(DRM_IOCTL_PRIME_FD_TO_HANDLE);
        SIMPLE_CASE(DRM_IOCTL_AGP_ACQUIRE);
        SIMPLE_CASE(DRM_IOCTL_AGP_RELEASE);
        SIMPLE_CASE(DRM_IOCTL_CRTC_GET_SEQUENCE);
        SIMPLE_CASE(DRM_IOCTL_CRTC_QUEUE_SEQUENCE);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETRESOURCES);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETCRTC);
        SIMPLE_CASE(DRM_IOCTL_MODE_SETCRTC);
        SIMPLE_CASE(DRM_IOCTL_MODE_CURSOR);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETGAMMA);
        SIMPLE_CASE(DRM_IOCTL_MODE_SETGAMMA);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETENCODER);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETCONNECTOR);
        SIMPLE_CASE(DRM_IOCTL_MODE_ATTACHMODE);
        SIMPLE_CASE(DRM_IOCTL_MODE_DETACHMODE);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETPROPERTY);
        SIMPLE_CASE(DRM_IOCTL_MODE_SETPROPERTY);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETPROPBLOB);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETFB);
        SIMPLE_CASE(DRM_IOCTL_MODE_ADDFB);
        SIMPLE_CASE(DRM_IOCTL_MODE_RMFB);
        SIMPLE_CASE(DRM_IOCTL_MODE_PAGE_FLIP);
        SIMPLE_CASE(DRM_IOCTL_MODE_DIRTYFB);
        SIMPLE_CASE(DRM_IOCTL_MODE_CREATE_DUMB);
        SIMPLE_CASE(DRM_IOCTL_MODE_MAP_DUMB);
        SIMPLE_CASE(DRM_IOCTL_MODE_DESTROY_DUMB);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETPLANERESOURCES);
        SIMPLE_CASE(DRM_IOCTL_MODE_GETPLANE);
        SIMPLE_CASE(DRM_IOCTL_MODE_SETPLANE);
        SIMPLE_CASE(DRM_IOCTL_MODE_OBJ_GETPROPERTIES);
        SIMPLE_CASE(DRM_IOCTL_MODE_OBJ_SETPROPERTY);
        SIMPLE_CASE(DRM_IOCTL_MODE_CURSOR2);
        SIMPLE_CASE(DRM_IOCTL_MODE_ATOMIC);
        SIMPLE_CASE(DRM_IOCTL_MODE_CREATEPROPBLOB);
        SIMPLE_CASE(DRM_IOCTL_MODE_DESTROYPROPBLOB);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_CREATE);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_DESTROY);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_HANDLE_TO_FD);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_FD_TO_HANDLE);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_WAIT);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_RESET);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_SIGNAL);
        SIMPLE_CASE(DRM_IOCTL_MODE_CREATE_LEASE);
        SIMPLE_CASE(DRM_IOCTL_MODE_LIST_LESSEES);
        SIMPLE_CASE(DRM_IOCTL_MODE_GET_LEASE);
        SIMPLE_CASE(DRM_IOCTL_MODE_REVOKE_LEASE);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_TIMELINE_WAIT);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_QUERY);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_TRANSFER);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_TIMELINE_SIGNAL);
        SIMPLE_CASE(DRM_IOCTL_SYNCOBJ_EVENTFD);
        SIMPLE_CASE(DRM_IOCTL_MODE_CLOSEFB);
        SIMPLE_CASE(DRM_IOCTL_SET_CLIENT_NAME);

    case DRM_COMMAND_BASE ... DRM_COMMAND_END - 1: {
        auto handler = Ioctl32::getHandler(fd);
        return handler(fd, cmd, args);
    }

    default: {
        ERROR("Unknown drm ioctl cmd: %x", cmd);
        return -1;
    }
    }
}