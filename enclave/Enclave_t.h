#ifndef ENCLAVE_T_H__
#define ENCLAVE_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */

#include "time.h"
#include "inc/stat.h"
#include "sys/uio.h"
#include "inc/stat.h"
#include "inc/dirent.h"
#include "sched.h"
#include "time.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _op_id_t
#define _op_id_t
typedef struct op_id_t {
	uint64_t h;
} op_id_t;
#endif

#ifndef _cache_meta_t
#define _cache_meta_t
typedef struct cache_meta_t {
	size_t caching_rdd_id;
	struct op_id_t caching_op_id;
	size_t caching_part_id;
	size_t cached_rdd_id;
	struct op_id_t cached_op_id;
	size_t cached_part_id;
} cache_meta_t;
#endif

#ifndef _dep_info_t
#define _dep_info_t
typedef struct dep_info_t {
	uint8_t is_shuffle;
	size_t identifier;
	size_t parent_rdd_id;
	size_t child_rdd_id;
	struct op_id_t parent_op_id;
	struct op_id_t child_op_id;
} dep_info_t;
#endif

#ifndef _input_t
#define _input_t
typedef struct input_t {
	size_t data;
	size_t marks;
	size_t parallel_num;
} input_t;
#endif

void secure_execute_pre(uint64_t tid, uint8_t* op_ids, uint8_t* part_nums, struct dep_info_t dep_info);
size_t secure_execute(uint64_t tid, size_t stage_id, uint8_t* rdd_ids, uint8_t* op_ids, uint8_t* part_ids, struct cache_meta_t cache_meta, struct dep_info_t dep_info, struct input_t input, uint8_t* captured_vars, size_t* addi_fields);
void free_res_enc(struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* data, uint8_t* marks);
void priv_free_res_enc(struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* data, uint8_t* marks);
void get_sketch(struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* p_buf, uint8_t* p_data_enc);
void clone_out(struct op_id_t op_id, struct dep_info_t dep_info, size_t p_out, uint8_t* p_data_enc);
size_t randomize_in_place(struct op_id_t op_id, uint8_t* input, uint64_t seed, uint8_t is_some, uint64_t num);
void set_sampler(struct op_id_t op_id, uint8_t with_replacement, double fraction);
size_t etake(struct op_id_t op_id, uint8_t* input, size_t should_take, size_t* have_take);
size_t tail_compute(uint8_t* input);
void free_tail_info(uint8_t* input);
void clear_cache(void);
size_t pre_touching(uint8_t zero);
void t_global_init_ecall(uint64_t id, const uint8_t* path, size_t len);
void t_global_exit_ecall(void);

sgx_status_t SGX_CDECL ocall_cache_to_outside(uint8_t* retval, size_t rdd_id, size_t part_id, size_t data_ptr, size_t marks_ptr);
sgx_status_t SGX_CDECL ocall_cache_from_outside(size_t* retval, size_t rdd_id, size_t part_id, size_t* marks_ptr);
sgx_status_t SGX_CDECL sbrk_o(void** retval, size_t size);
sgx_status_t SGX_CDECL u_thread_set_event_ocall(int* retval, int* error, const void* tcs);
sgx_status_t SGX_CDECL u_thread_wait_event_ocall(int* retval, int* error, const void* tcs, const struct timespec* timeout);
sgx_status_t SGX_CDECL u_thread_set_multiple_events_ocall(int* retval, int* error, const void** tcss, int total);
sgx_status_t SGX_CDECL u_thread_setwait_events_ocall(int* retval, int* error, const void* waiter_tcs, const void* self_tcs, const struct timespec* timeout);
sgx_status_t SGX_CDECL u_clock_gettime_ocall(int* retval, int* error, int clk_id, struct timespec* tp);
sgx_status_t SGX_CDECL u_read_ocall(size_t* retval, int* error, int fd, void* buf, size_t count);
sgx_status_t SGX_CDECL u_pread64_ocall(size_t* retval, int* error, int fd, void* buf, size_t count, int64_t offset);
sgx_status_t SGX_CDECL u_readv_ocall(size_t* retval, int* error, int fd, const struct iovec* iov, int iovcnt);
sgx_status_t SGX_CDECL u_preadv64_ocall(size_t* retval, int* error, int fd, const struct iovec* iov, int iovcnt, int64_t offset);
sgx_status_t SGX_CDECL u_write_ocall(size_t* retval, int* error, int fd, const void* buf, size_t count);
sgx_status_t SGX_CDECL u_pwrite64_ocall(size_t* retval, int* error, int fd, const void* buf, size_t count, int64_t offset);
sgx_status_t SGX_CDECL u_writev_ocall(size_t* retval, int* error, int fd, const struct iovec* iov, int iovcnt);
sgx_status_t SGX_CDECL u_pwritev64_ocall(size_t* retval, int* error, int fd, const struct iovec* iov, int iovcnt, int64_t offset);
sgx_status_t SGX_CDECL u_fcntl_arg0_ocall(int* retval, int* error, int fd, int cmd);
sgx_status_t SGX_CDECL u_fcntl_arg1_ocall(int* retval, int* error, int fd, int cmd, int arg);
sgx_status_t SGX_CDECL u_ioctl_arg0_ocall(int* retval, int* error, int fd, int request);
sgx_status_t SGX_CDECL u_ioctl_arg1_ocall(int* retval, int* error, int fd, int request, int* arg);
sgx_status_t SGX_CDECL u_close_ocall(int* retval, int* error, int fd);
sgx_status_t SGX_CDECL u_malloc_ocall(void** retval, int* error, size_t size);
sgx_status_t SGX_CDECL u_free_ocall(void* p);
sgx_status_t SGX_CDECL u_mmap_ocall(void** retval, int* error, void* start, size_t length, int prot, int flags, int fd, int64_t offset);
sgx_status_t SGX_CDECL u_munmap_ocall(int* retval, int* error, void* start, size_t length);
sgx_status_t SGX_CDECL u_msync_ocall(int* retval, int* error, void* addr, size_t length, int flags);
sgx_status_t SGX_CDECL u_mprotect_ocall(int* retval, int* error, void* addr, size_t length, int prot);
sgx_status_t SGX_CDECL u_open_ocall(int* retval, int* error, const char* pathname, int flags);
sgx_status_t SGX_CDECL u_open64_ocall(int* retval, int* error, const char* path, int oflag, int mode);
sgx_status_t SGX_CDECL u_fstat_ocall(int* retval, int* error, int fd, struct stat_t* buf);
sgx_status_t SGX_CDECL u_fstat64_ocall(int* retval, int* error, int fd, struct stat64_t* buf);
sgx_status_t SGX_CDECL u_stat_ocall(int* retval, int* error, const char* path, struct stat_t* buf);
sgx_status_t SGX_CDECL u_stat64_ocall(int* retval, int* error, const char* path, struct stat64_t* buf);
sgx_status_t SGX_CDECL u_lstat_ocall(int* retval, int* error, const char* path, struct stat_t* buf);
sgx_status_t SGX_CDECL u_lstat64_ocall(int* retval, int* error, const char* path, struct stat64_t* buf);
sgx_status_t SGX_CDECL u_lseek_ocall(uint64_t* retval, int* error, int fd, int64_t offset, int whence);
sgx_status_t SGX_CDECL u_lseek64_ocall(int64_t* retval, int* error, int fd, int64_t offset, int whence);
sgx_status_t SGX_CDECL u_ftruncate_ocall(int* retval, int* error, int fd, int64_t length);
sgx_status_t SGX_CDECL u_ftruncate64_ocall(int* retval, int* error, int fd, int64_t length);
sgx_status_t SGX_CDECL u_truncate_ocall(int* retval, int* error, const char* path, int64_t length);
sgx_status_t SGX_CDECL u_truncate64_ocall(int* retval, int* error, const char* path, int64_t length);
sgx_status_t SGX_CDECL u_fsync_ocall(int* retval, int* error, int fd);
sgx_status_t SGX_CDECL u_fdatasync_ocall(int* retval, int* error, int fd);
sgx_status_t SGX_CDECL u_fchmod_ocall(int* retval, int* error, int fd, uint32_t mode);
sgx_status_t SGX_CDECL u_unlink_ocall(int* retval, int* error, const char* pathname);
sgx_status_t SGX_CDECL u_link_ocall(int* retval, int* error, const char* oldpath, const char* newpath);
sgx_status_t SGX_CDECL u_rename_ocall(int* retval, int* error, const char* oldpath, const char* newpath);
sgx_status_t SGX_CDECL u_chmod_ocall(int* retval, int* error, const char* path, uint32_t mode);
sgx_status_t SGX_CDECL u_readlink_ocall(size_t* retval, int* error, const char* path, char* buf, size_t bufsz);
sgx_status_t SGX_CDECL u_symlink_ocall(int* retval, int* error, const char* path1, const char* path2);
sgx_status_t SGX_CDECL u_realpath_ocall(char** retval, int* error, const char* pathname);
sgx_status_t SGX_CDECL u_mkdir_ocall(int* retval, int* error, const char* pathname, uint32_t mode);
sgx_status_t SGX_CDECL u_rmdir_ocall(int* retval, int* error, const char* pathname);
sgx_status_t SGX_CDECL u_opendir_ocall(void** retval, int* error, const char* pathname);
sgx_status_t SGX_CDECL u_readdir64_r_ocall(int* retval, void* dirp, struct dirent64_t* entry, struct dirent64_t** result);
sgx_status_t SGX_CDECL u_closedir_ocall(int* retval, int* error, void* dirp);
sgx_status_t SGX_CDECL u_dirfd_ocall(int* retval, int* error, void* dirp);
sgx_status_t SGX_CDECL u_fstatat64_ocall(int* retval, int* error, int dirfd, const char* pathname, struct stat64_t* buf, int flags);
sgx_status_t SGX_CDECL sgx_oc_cpuidex(int cpuinfo[4], int leaf, int subleaf);
sgx_status_t SGX_CDECL sgx_thread_wait_untrusted_event_ocall(int* retval, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_untrusted_event_ocall(int* retval, const void* waiter);
sgx_status_t SGX_CDECL sgx_thread_setwait_untrusted_events_ocall(int* retval, const void* waiter, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_multiple_untrusted_events_ocall(int* retval, const void** waiters, size_t total);
sgx_status_t SGX_CDECL pthread_wait_timeout_ocall(int* retval, unsigned long long waiter, unsigned long long timeout);
sgx_status_t SGX_CDECL pthread_create_ocall(int* retval, unsigned long long self);
sgx_status_t SGX_CDECL pthread_wakeup_ocall(int* retval, unsigned long long waiter);
sgx_status_t SGX_CDECL u_sysconf_ocall(long int* retval, int* error, int name);
sgx_status_t SGX_CDECL u_prctl_ocall(int* retval, int* error, int option, unsigned long int arg2, unsigned long int arg3, unsigned long int arg4, unsigned long int arg5);
sgx_status_t SGX_CDECL u_sched_setaffinity_ocall(int* retval, int* error, pid_t pid, size_t cpusetsize, cpu_set_t* mask);
sgx_status_t SGX_CDECL u_sched_getaffinity_ocall(int* retval, int* error, pid_t pid, size_t cpusetsize, cpu_set_t* mask);
sgx_status_t SGX_CDECL u_sched_yield_ocall(int* retval, int* error);
sgx_status_t SGX_CDECL u_nanosleep_ocall(int* retval, int* error, const struct timespec* req, struct timespec* rem);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
