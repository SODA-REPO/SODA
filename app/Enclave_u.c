#include "Enclave_u.h"
#include <errno.h>

typedef struct ms_secure_execute_pre_t {
	uint64_t ms_tid;
	uint8_t* ms_op_ids;
	uint8_t* ms_part_nums;
	struct dep_info_t ms_dep_info;
} ms_secure_execute_pre_t;

typedef struct ms_secure_execute_t {
	size_t ms_retval;
	uint64_t ms_tid;
	size_t ms_stage_id;
	uint8_t* ms_rdd_ids;
	uint8_t* ms_op_ids;
	uint8_t* ms_part_ids;
	struct cache_meta_t ms_cache_meta;
	struct dep_info_t ms_dep_info;
	struct input_t ms_input;
	uint8_t* ms_captured_vars;
	size_t* ms_addi_fields;
} ms_secure_execute_t;

typedef struct ms_free_res_enc_t {
	struct op_id_t ms_op_id;
	struct dep_info_t ms_dep_info;
	uint8_t* ms_data;
	uint8_t* ms_marks;
} ms_free_res_enc_t;

typedef struct ms_priv_free_res_enc_t {
	struct op_id_t ms_op_id;
	struct dep_info_t ms_dep_info;
	uint8_t* ms_data;
	uint8_t* ms_marks;
} ms_priv_free_res_enc_t;

typedef struct ms_get_sketch_t {
	struct op_id_t ms_op_id;
	struct dep_info_t ms_dep_info;
	uint8_t* ms_p_buf;
	uint8_t* ms_p_data_enc;
} ms_get_sketch_t;

typedef struct ms_clone_out_t {
	struct op_id_t ms_op_id;
	struct dep_info_t ms_dep_info;
	size_t ms_p_out;
	uint8_t* ms_p_data_enc;
} ms_clone_out_t;

typedef struct ms_randomize_in_place_t {
	size_t ms_retval;
	struct op_id_t ms_op_id;
	uint8_t* ms_input;
	uint64_t ms_seed;
	uint8_t ms_is_some;
	uint64_t ms_num;
} ms_randomize_in_place_t;

typedef struct ms_set_sampler_t {
	struct op_id_t ms_op_id;
	uint8_t ms_with_replacement;
	double ms_fraction;
} ms_set_sampler_t;

typedef struct ms_etake_t {
	size_t ms_retval;
	struct op_id_t ms_op_id;
	uint8_t* ms_input;
	size_t ms_should_take;
	size_t* ms_have_take;
} ms_etake_t;

typedef struct ms_tail_compute_t {
	size_t ms_retval;
	uint8_t* ms_input;
} ms_tail_compute_t;

typedef struct ms_free_tail_info_t {
	uint8_t* ms_input;
} ms_free_tail_info_t;

typedef struct ms_pre_touching_t {
	size_t ms_retval;
	uint8_t ms_zero;
} ms_pre_touching_t;

typedef struct ms_t_global_init_ecall_t {
	uint64_t ms_id;
	const uint8_t* ms_path;
	size_t ms_len;
} ms_t_global_init_ecall_t;

typedef struct ms_ocall_cache_to_outside_t {
	uint8_t ms_retval;
	size_t ms_rdd_id;
	size_t ms_part_id;
	size_t ms_data_ptr;
	size_t ms_marks_ptr;
} ms_ocall_cache_to_outside_t;

typedef struct ms_ocall_cache_from_outside_t {
	size_t ms_retval;
	size_t ms_rdd_id;
	size_t ms_part_id;
	size_t* ms_marks_ptr;
} ms_ocall_cache_from_outside_t;

typedef struct ms_sbrk_o_t {
	void* ms_retval;
	size_t ms_size;
} ms_sbrk_o_t;

typedef struct ms_u_thread_set_event_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_tcs;
} ms_u_thread_set_event_ocall_t;

typedef struct ms_u_thread_wait_event_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_tcs;
	const struct timespec* ms_timeout;
} ms_u_thread_wait_event_ocall_t;

typedef struct ms_u_thread_set_multiple_events_ocall_t {
	int ms_retval;
	int* ms_error;
	const void** ms_tcss;
	int ms_total;
} ms_u_thread_set_multiple_events_ocall_t;

typedef struct ms_u_thread_setwait_events_ocall_t {
	int ms_retval;
	int* ms_error;
	const void* ms_waiter_tcs;
	const void* ms_self_tcs;
	const struct timespec* ms_timeout;
} ms_u_thread_setwait_events_ocall_t;

typedef struct ms_u_clock_gettime_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_clk_id;
	struct timespec* ms_tp;
} ms_u_clock_gettime_ocall_t;

typedef struct ms_u_read_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	void* ms_buf;
	size_t ms_count;
} ms_u_read_ocall_t;

typedef struct ms_u_pread64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	void* ms_buf;
	size_t ms_count;
	int64_t ms_offset;
} ms_u_pread64_ocall_t;

typedef struct ms_u_readv_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
} ms_u_readv_ocall_t;

typedef struct ms_u_preadv64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
	int64_t ms_offset;
} ms_u_preadv64_ocall_t;

typedef struct ms_u_write_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const void* ms_buf;
	size_t ms_count;
} ms_u_write_ocall_t;

typedef struct ms_u_pwrite64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const void* ms_buf;
	size_t ms_count;
	int64_t ms_offset;
} ms_u_pwrite64_ocall_t;

typedef struct ms_u_writev_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
} ms_u_writev_ocall_t;

typedef struct ms_u_pwritev64_ocall_t {
	size_t ms_retval;
	int* ms_error;
	int ms_fd;
	const struct iovec* ms_iov;
	int ms_iovcnt;
	int64_t ms_offset;
} ms_u_pwritev64_ocall_t;

typedef struct ms_u_fcntl_arg0_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_cmd;
} ms_u_fcntl_arg0_ocall_t;

typedef struct ms_u_fcntl_arg1_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_cmd;
	int ms_arg;
} ms_u_fcntl_arg1_ocall_t;

typedef struct ms_u_ioctl_arg0_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_request;
} ms_u_ioctl_arg0_ocall_t;

typedef struct ms_u_ioctl_arg1_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int ms_request;
	int* ms_arg;
} ms_u_ioctl_arg1_ocall_t;

typedef struct ms_u_close_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_close_ocall_t;

typedef struct ms_u_malloc_ocall_t {
	void* ms_retval;
	int* ms_error;
	size_t ms_size;
} ms_u_malloc_ocall_t;

typedef struct ms_u_free_ocall_t {
	void* ms_p;
} ms_u_free_ocall_t;

typedef struct ms_u_mmap_ocall_t {
	void* ms_retval;
	int* ms_error;
	void* ms_start;
	size_t ms_length;
	int ms_prot;
	int ms_flags;
	int ms_fd;
	int64_t ms_offset;
} ms_u_mmap_ocall_t;

typedef struct ms_u_munmap_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_start;
	size_t ms_length;
} ms_u_munmap_ocall_t;

typedef struct ms_u_msync_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_addr;
	size_t ms_length;
	int ms_flags;
} ms_u_msync_ocall_t;

typedef struct ms_u_mprotect_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_addr;
	size_t ms_length;
	int ms_prot;
} ms_u_mprotect_ocall_t;

typedef struct ms_u_open_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
	int ms_flags;
} ms_u_open_ocall_t;

typedef struct ms_u_open64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int ms_oflag;
	int ms_mode;
} ms_u_open64_ocall_t;

typedef struct ms_u_fstat_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	struct stat_t* ms_buf;
} ms_u_fstat_ocall_t;

typedef struct ms_u_fstat64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	struct stat64_t* ms_buf;
} ms_u_fstat64_ocall_t;

typedef struct ms_u_stat_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat_t* ms_buf;
} ms_u_stat_ocall_t;

typedef struct ms_u_stat64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat64_t* ms_buf;
} ms_u_stat64_ocall_t;

typedef struct ms_u_lstat_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat_t* ms_buf;
} ms_u_lstat_ocall_t;

typedef struct ms_u_lstat64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	struct stat64_t* ms_buf;
} ms_u_lstat64_ocall_t;

typedef struct ms_u_lseek_ocall_t {
	uint64_t ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_offset;
	int ms_whence;
} ms_u_lseek_ocall_t;

typedef struct ms_u_lseek64_ocall_t {
	int64_t ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_offset;
	int ms_whence;
} ms_u_lseek64_ocall_t;

typedef struct ms_u_ftruncate_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_length;
} ms_u_ftruncate_ocall_t;

typedef struct ms_u_ftruncate64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	int64_t ms_length;
} ms_u_ftruncate64_ocall_t;

typedef struct ms_u_truncate_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int64_t ms_length;
} ms_u_truncate_ocall_t;

typedef struct ms_u_truncate64_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	int64_t ms_length;
} ms_u_truncate64_ocall_t;

typedef struct ms_u_fsync_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_fsync_ocall_t;

typedef struct ms_u_fdatasync_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
} ms_u_fdatasync_ocall_t;

typedef struct ms_u_fchmod_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_fd;
	uint32_t ms_mode;
} ms_u_fchmod_ocall_t;

typedef struct ms_u_unlink_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_unlink_ocall_t;

typedef struct ms_u_link_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_oldpath;
	const char* ms_newpath;
} ms_u_link_ocall_t;

typedef struct ms_u_rename_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_oldpath;
	const char* ms_newpath;
} ms_u_rename_ocall_t;

typedef struct ms_u_chmod_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path;
	uint32_t ms_mode;
} ms_u_chmod_ocall_t;

typedef struct ms_u_readlink_ocall_t {
	size_t ms_retval;
	int* ms_error;
	const char* ms_path;
	char* ms_buf;
	size_t ms_bufsz;
} ms_u_readlink_ocall_t;

typedef struct ms_u_symlink_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_path1;
	const char* ms_path2;
} ms_u_symlink_ocall_t;

typedef struct ms_u_realpath_ocall_t {
	char* ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_realpath_ocall_t;

typedef struct ms_u_mkdir_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
	uint32_t ms_mode;
} ms_u_mkdir_ocall_t;

typedef struct ms_u_rmdir_ocall_t {
	int ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_rmdir_ocall_t;

typedef struct ms_u_opendir_ocall_t {
	void* ms_retval;
	int* ms_error;
	const char* ms_pathname;
} ms_u_opendir_ocall_t;

typedef struct ms_u_readdir64_r_ocall_t {
	int ms_retval;
	void* ms_dirp;
	struct dirent64_t* ms_entry;
	struct dirent64_t** ms_result;
} ms_u_readdir64_r_ocall_t;

typedef struct ms_u_closedir_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_dirp;
} ms_u_closedir_ocall_t;

typedef struct ms_u_dirfd_ocall_t {
	int ms_retval;
	int* ms_error;
	void* ms_dirp;
} ms_u_dirfd_ocall_t;

typedef struct ms_u_fstatat64_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_dirfd;
	const char* ms_pathname;
	struct stat64_t* ms_buf;
	int ms_flags;
} ms_u_fstatat64_ocall_t;

typedef struct ms_sgx_oc_cpuidex_t {
	int* ms_cpuinfo;
	int ms_leaf;
	int ms_subleaf;
} ms_sgx_oc_cpuidex_t;

typedef struct ms_sgx_thread_wait_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_self;
} ms_sgx_thread_wait_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_set_untrusted_event_ocall_t {
	int ms_retval;
	const void* ms_waiter;
} ms_sgx_thread_set_untrusted_event_ocall_t;

typedef struct ms_sgx_thread_setwait_untrusted_events_ocall_t {
	int ms_retval;
	const void* ms_waiter;
	const void* ms_self;
} ms_sgx_thread_setwait_untrusted_events_ocall_t;

typedef struct ms_sgx_thread_set_multiple_untrusted_events_ocall_t {
	int ms_retval;
	const void** ms_waiters;
	size_t ms_total;
} ms_sgx_thread_set_multiple_untrusted_events_ocall_t;

typedef struct ms_pthread_wait_timeout_ocall_t {
	int ms_retval;
	unsigned long long ms_waiter;
	unsigned long long ms_timeout;
} ms_pthread_wait_timeout_ocall_t;

typedef struct ms_pthread_create_ocall_t {
	int ms_retval;
	unsigned long long ms_self;
} ms_pthread_create_ocall_t;

typedef struct ms_pthread_wakeup_ocall_t {
	int ms_retval;
	unsigned long long ms_waiter;
} ms_pthread_wakeup_ocall_t;

typedef struct ms_u_sysconf_ocall_t {
	long int ms_retval;
	int* ms_error;
	int ms_name;
} ms_u_sysconf_ocall_t;

typedef struct ms_u_prctl_ocall_t {
	int ms_retval;
	int* ms_error;
	int ms_option;
	unsigned long int ms_arg2;
	unsigned long int ms_arg3;
	unsigned long int ms_arg4;
	unsigned long int ms_arg5;
} ms_u_prctl_ocall_t;

typedef struct ms_u_sched_setaffinity_ocall_t {
	int ms_retval;
	int* ms_error;
	pid_t ms_pid;
	size_t ms_cpusetsize;
	cpu_set_t* ms_mask;
} ms_u_sched_setaffinity_ocall_t;

typedef struct ms_u_sched_getaffinity_ocall_t {
	int ms_retval;
	int* ms_error;
	pid_t ms_pid;
	size_t ms_cpusetsize;
	cpu_set_t* ms_mask;
} ms_u_sched_getaffinity_ocall_t;

typedef struct ms_u_sched_yield_ocall_t {
	int ms_retval;
	int* ms_error;
} ms_u_sched_yield_ocall_t;

typedef struct ms_u_nanosleep_ocall_t {
	int ms_retval;
	int* ms_error;
	const struct timespec* ms_req;
	struct timespec* ms_rem;
} ms_u_nanosleep_ocall_t;

static sgx_status_t SGX_CDECL Enclave_ocall_cache_to_outside(void* pms)
{
	ms_ocall_cache_to_outside_t* ms = SGX_CAST(ms_ocall_cache_to_outside_t*, pms);
	ms->ms_retval = ocall_cache_to_outside(ms->ms_rdd_id, ms->ms_part_id, ms->ms_data_ptr, ms->ms_marks_ptr);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_ocall_cache_from_outside(void* pms)
{
	ms_ocall_cache_from_outside_t* ms = SGX_CAST(ms_ocall_cache_from_outside_t*, pms);
	ms->ms_retval = ocall_cache_from_outside(ms->ms_rdd_id, ms->ms_part_id, ms->ms_marks_ptr);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sbrk_o(void* pms)
{
	ms_sbrk_o_t* ms = SGX_CAST(ms_sbrk_o_t*, pms);
	ms->ms_retval = sbrk_o(ms->ms_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_set_event_ocall(void* pms)
{
	ms_u_thread_set_event_ocall_t* ms = SGX_CAST(ms_u_thread_set_event_ocall_t*, pms);
	ms->ms_retval = u_thread_set_event_ocall(ms->ms_error, ms->ms_tcs);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_wait_event_ocall(void* pms)
{
	ms_u_thread_wait_event_ocall_t* ms = SGX_CAST(ms_u_thread_wait_event_ocall_t*, pms);
	ms->ms_retval = u_thread_wait_event_ocall(ms->ms_error, ms->ms_tcs, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_set_multiple_events_ocall(void* pms)
{
	ms_u_thread_set_multiple_events_ocall_t* ms = SGX_CAST(ms_u_thread_set_multiple_events_ocall_t*, pms);
	ms->ms_retval = u_thread_set_multiple_events_ocall(ms->ms_error, ms->ms_tcss, ms->ms_total);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_thread_setwait_events_ocall(void* pms)
{
	ms_u_thread_setwait_events_ocall_t* ms = SGX_CAST(ms_u_thread_setwait_events_ocall_t*, pms);
	ms->ms_retval = u_thread_setwait_events_ocall(ms->ms_error, ms->ms_waiter_tcs, ms->ms_self_tcs, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_clock_gettime_ocall(void* pms)
{
	ms_u_clock_gettime_ocall_t* ms = SGX_CAST(ms_u_clock_gettime_ocall_t*, pms);
	ms->ms_retval = u_clock_gettime_ocall(ms->ms_error, ms->ms_clk_id, ms->ms_tp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_read_ocall(void* pms)
{
	ms_u_read_ocall_t* ms = SGX_CAST(ms_u_read_ocall_t*, pms);
	ms->ms_retval = u_read_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pread64_ocall(void* pms)
{
	ms_u_pread64_ocall_t* ms = SGX_CAST(ms_u_pread64_ocall_t*, pms);
	ms->ms_retval = u_pread64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readv_ocall(void* pms)
{
	ms_u_readv_ocall_t* ms = SGX_CAST(ms_u_readv_ocall_t*, pms);
	ms->ms_retval = u_readv_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_preadv64_ocall(void* pms)
{
	ms_u_preadv64_ocall_t* ms = SGX_CAST(ms_u_preadv64_ocall_t*, pms);
	ms->ms_retval = u_preadv64_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_write_ocall(void* pms)
{
	ms_u_write_ocall_t* ms = SGX_CAST(ms_u_write_ocall_t*, pms);
	ms->ms_retval = u_write_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pwrite64_ocall(void* pms)
{
	ms_u_pwrite64_ocall_t* ms = SGX_CAST(ms_u_pwrite64_ocall_t*, pms);
	ms->ms_retval = u_pwrite64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf, ms->ms_count, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_writev_ocall(void* pms)
{
	ms_u_writev_ocall_t* ms = SGX_CAST(ms_u_writev_ocall_t*, pms);
	ms->ms_retval = u_writev_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_pwritev64_ocall(void* pms)
{
	ms_u_pwritev64_ocall_t* ms = SGX_CAST(ms_u_pwritev64_ocall_t*, pms);
	ms->ms_retval = u_pwritev64_ocall(ms->ms_error, ms->ms_fd, ms->ms_iov, ms->ms_iovcnt, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fcntl_arg0_ocall(void* pms)
{
	ms_u_fcntl_arg0_ocall_t* ms = SGX_CAST(ms_u_fcntl_arg0_ocall_t*, pms);
	ms->ms_retval = u_fcntl_arg0_ocall(ms->ms_error, ms->ms_fd, ms->ms_cmd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fcntl_arg1_ocall(void* pms)
{
	ms_u_fcntl_arg1_ocall_t* ms = SGX_CAST(ms_u_fcntl_arg1_ocall_t*, pms);
	ms->ms_retval = u_fcntl_arg1_ocall(ms->ms_error, ms->ms_fd, ms->ms_cmd, ms->ms_arg);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ioctl_arg0_ocall(void* pms)
{
	ms_u_ioctl_arg0_ocall_t* ms = SGX_CAST(ms_u_ioctl_arg0_ocall_t*, pms);
	ms->ms_retval = u_ioctl_arg0_ocall(ms->ms_error, ms->ms_fd, ms->ms_request);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ioctl_arg1_ocall(void* pms)
{
	ms_u_ioctl_arg1_ocall_t* ms = SGX_CAST(ms_u_ioctl_arg1_ocall_t*, pms);
	ms->ms_retval = u_ioctl_arg1_ocall(ms->ms_error, ms->ms_fd, ms->ms_request, ms->ms_arg);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_close_ocall(void* pms)
{
	ms_u_close_ocall_t* ms = SGX_CAST(ms_u_close_ocall_t*, pms);
	ms->ms_retval = u_close_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_malloc_ocall(void* pms)
{
	ms_u_malloc_ocall_t* ms = SGX_CAST(ms_u_malloc_ocall_t*, pms);
	ms->ms_retval = u_malloc_ocall(ms->ms_error, ms->ms_size);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_free_ocall(void* pms)
{
	ms_u_free_ocall_t* ms = SGX_CAST(ms_u_free_ocall_t*, pms);
	u_free_ocall(ms->ms_p);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mmap_ocall(void* pms)
{
	ms_u_mmap_ocall_t* ms = SGX_CAST(ms_u_mmap_ocall_t*, pms);
	ms->ms_retval = u_mmap_ocall(ms->ms_error, ms->ms_start, ms->ms_length, ms->ms_prot, ms->ms_flags, ms->ms_fd, ms->ms_offset);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_munmap_ocall(void* pms)
{
	ms_u_munmap_ocall_t* ms = SGX_CAST(ms_u_munmap_ocall_t*, pms);
	ms->ms_retval = u_munmap_ocall(ms->ms_error, ms->ms_start, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_msync_ocall(void* pms)
{
	ms_u_msync_ocall_t* ms = SGX_CAST(ms_u_msync_ocall_t*, pms);
	ms->ms_retval = u_msync_ocall(ms->ms_error, ms->ms_addr, ms->ms_length, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mprotect_ocall(void* pms)
{
	ms_u_mprotect_ocall_t* ms = SGX_CAST(ms_u_mprotect_ocall_t*, pms);
	ms->ms_retval = u_mprotect_ocall(ms->ms_error, ms->ms_addr, ms->ms_length, ms->ms_prot);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_open_ocall(void* pms)
{
	ms_u_open_ocall_t* ms = SGX_CAST(ms_u_open_ocall_t*, pms);
	ms->ms_retval = u_open_ocall(ms->ms_error, ms->ms_pathname, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_open64_ocall(void* pms)
{
	ms_u_open64_ocall_t* ms = SGX_CAST(ms_u_open64_ocall_t*, pms);
	ms->ms_retval = u_open64_ocall(ms->ms_error, ms->ms_path, ms->ms_oflag, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstat_ocall(void* pms)
{
	ms_u_fstat_ocall_t* ms = SGX_CAST(ms_u_fstat_ocall_t*, pms);
	ms->ms_retval = u_fstat_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstat64_ocall(void* pms)
{
	ms_u_fstat64_ocall_t* ms = SGX_CAST(ms_u_fstat64_ocall_t*, pms);
	ms->ms_retval = u_fstat64_ocall(ms->ms_error, ms->ms_fd, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_stat_ocall(void* pms)
{
	ms_u_stat_ocall_t* ms = SGX_CAST(ms_u_stat_ocall_t*, pms);
	ms->ms_retval = u_stat_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_stat64_ocall(void* pms)
{
	ms_u_stat64_ocall_t* ms = SGX_CAST(ms_u_stat64_ocall_t*, pms);
	ms->ms_retval = u_stat64_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lstat_ocall(void* pms)
{
	ms_u_lstat_ocall_t* ms = SGX_CAST(ms_u_lstat_ocall_t*, pms);
	ms->ms_retval = u_lstat_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lstat64_ocall(void* pms)
{
	ms_u_lstat64_ocall_t* ms = SGX_CAST(ms_u_lstat64_ocall_t*, pms);
	ms->ms_retval = u_lstat64_ocall(ms->ms_error, ms->ms_path, ms->ms_buf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lseek_ocall(void* pms)
{
	ms_u_lseek_ocall_t* ms = SGX_CAST(ms_u_lseek_ocall_t*, pms);
	ms->ms_retval = u_lseek_ocall(ms->ms_error, ms->ms_fd, ms->ms_offset, ms->ms_whence);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_lseek64_ocall(void* pms)
{
	ms_u_lseek64_ocall_t* ms = SGX_CAST(ms_u_lseek64_ocall_t*, pms);
	ms->ms_retval = u_lseek64_ocall(ms->ms_error, ms->ms_fd, ms->ms_offset, ms->ms_whence);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ftruncate_ocall(void* pms)
{
	ms_u_ftruncate_ocall_t* ms = SGX_CAST(ms_u_ftruncate_ocall_t*, pms);
	ms->ms_retval = u_ftruncate_ocall(ms->ms_error, ms->ms_fd, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_ftruncate64_ocall(void* pms)
{
	ms_u_ftruncate64_ocall_t* ms = SGX_CAST(ms_u_ftruncate64_ocall_t*, pms);
	ms->ms_retval = u_ftruncate64_ocall(ms->ms_error, ms->ms_fd, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_truncate_ocall(void* pms)
{
	ms_u_truncate_ocall_t* ms = SGX_CAST(ms_u_truncate_ocall_t*, pms);
	ms->ms_retval = u_truncate_ocall(ms->ms_error, ms->ms_path, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_truncate64_ocall(void* pms)
{
	ms_u_truncate64_ocall_t* ms = SGX_CAST(ms_u_truncate64_ocall_t*, pms);
	ms->ms_retval = u_truncate64_ocall(ms->ms_error, ms->ms_path, ms->ms_length);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fsync_ocall(void* pms)
{
	ms_u_fsync_ocall_t* ms = SGX_CAST(ms_u_fsync_ocall_t*, pms);
	ms->ms_retval = u_fsync_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fdatasync_ocall(void* pms)
{
	ms_u_fdatasync_ocall_t* ms = SGX_CAST(ms_u_fdatasync_ocall_t*, pms);
	ms->ms_retval = u_fdatasync_ocall(ms->ms_error, ms->ms_fd);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fchmod_ocall(void* pms)
{
	ms_u_fchmod_ocall_t* ms = SGX_CAST(ms_u_fchmod_ocall_t*, pms);
	ms->ms_retval = u_fchmod_ocall(ms->ms_error, ms->ms_fd, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_unlink_ocall(void* pms)
{
	ms_u_unlink_ocall_t* ms = SGX_CAST(ms_u_unlink_ocall_t*, pms);
	ms->ms_retval = u_unlink_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_link_ocall(void* pms)
{
	ms_u_link_ocall_t* ms = SGX_CAST(ms_u_link_ocall_t*, pms);
	ms->ms_retval = u_link_ocall(ms->ms_error, ms->ms_oldpath, ms->ms_newpath);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_rename_ocall(void* pms)
{
	ms_u_rename_ocall_t* ms = SGX_CAST(ms_u_rename_ocall_t*, pms);
	ms->ms_retval = u_rename_ocall(ms->ms_error, ms->ms_oldpath, ms->ms_newpath);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_chmod_ocall(void* pms)
{
	ms_u_chmod_ocall_t* ms = SGX_CAST(ms_u_chmod_ocall_t*, pms);
	ms->ms_retval = u_chmod_ocall(ms->ms_error, ms->ms_path, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readlink_ocall(void* pms)
{
	ms_u_readlink_ocall_t* ms = SGX_CAST(ms_u_readlink_ocall_t*, pms);
	ms->ms_retval = u_readlink_ocall(ms->ms_error, ms->ms_path, ms->ms_buf, ms->ms_bufsz);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_symlink_ocall(void* pms)
{
	ms_u_symlink_ocall_t* ms = SGX_CAST(ms_u_symlink_ocall_t*, pms);
	ms->ms_retval = u_symlink_ocall(ms->ms_error, ms->ms_path1, ms->ms_path2);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_realpath_ocall(void* pms)
{
	ms_u_realpath_ocall_t* ms = SGX_CAST(ms_u_realpath_ocall_t*, pms);
	ms->ms_retval = u_realpath_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_mkdir_ocall(void* pms)
{
	ms_u_mkdir_ocall_t* ms = SGX_CAST(ms_u_mkdir_ocall_t*, pms);
	ms->ms_retval = u_mkdir_ocall(ms->ms_error, ms->ms_pathname, ms->ms_mode);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_rmdir_ocall(void* pms)
{
	ms_u_rmdir_ocall_t* ms = SGX_CAST(ms_u_rmdir_ocall_t*, pms);
	ms->ms_retval = u_rmdir_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_opendir_ocall(void* pms)
{
	ms_u_opendir_ocall_t* ms = SGX_CAST(ms_u_opendir_ocall_t*, pms);
	ms->ms_retval = u_opendir_ocall(ms->ms_error, ms->ms_pathname);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_readdir64_r_ocall(void* pms)
{
	ms_u_readdir64_r_ocall_t* ms = SGX_CAST(ms_u_readdir64_r_ocall_t*, pms);
	ms->ms_retval = u_readdir64_r_ocall(ms->ms_dirp, ms->ms_entry, ms->ms_result);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_closedir_ocall(void* pms)
{
	ms_u_closedir_ocall_t* ms = SGX_CAST(ms_u_closedir_ocall_t*, pms);
	ms->ms_retval = u_closedir_ocall(ms->ms_error, ms->ms_dirp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_dirfd_ocall(void* pms)
{
	ms_u_dirfd_ocall_t* ms = SGX_CAST(ms_u_dirfd_ocall_t*, pms);
	ms->ms_retval = u_dirfd_ocall(ms->ms_error, ms->ms_dirp);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_fstatat64_ocall(void* pms)
{
	ms_u_fstatat64_ocall_t* ms = SGX_CAST(ms_u_fstatat64_ocall_t*, pms);
	ms->ms_retval = u_fstatat64_ocall(ms->ms_error, ms->ms_dirfd, ms->ms_pathname, ms->ms_buf, ms->ms_flags);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_oc_cpuidex(void* pms)
{
	ms_sgx_oc_cpuidex_t* ms = SGX_CAST(ms_sgx_oc_cpuidex_t*, pms);
	sgx_oc_cpuidex(ms->ms_cpuinfo, ms->ms_leaf, ms->ms_subleaf);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_wait_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_wait_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_wait_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_wait_untrusted_event_ocall(ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_set_untrusted_event_ocall(void* pms)
{
	ms_sgx_thread_set_untrusted_event_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_untrusted_event_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_untrusted_event_ocall(ms->ms_waiter);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_setwait_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_setwait_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_setwait_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_setwait_untrusted_events_ocall(ms->ms_waiter, ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_sgx_thread_set_multiple_untrusted_events_ocall(void* pms)
{
	ms_sgx_thread_set_multiple_untrusted_events_ocall_t* ms = SGX_CAST(ms_sgx_thread_set_multiple_untrusted_events_ocall_t*, pms);
	ms->ms_retval = sgx_thread_set_multiple_untrusted_events_ocall(ms->ms_waiters, ms->ms_total);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_pthread_wait_timeout_ocall(void* pms)
{
	ms_pthread_wait_timeout_ocall_t* ms = SGX_CAST(ms_pthread_wait_timeout_ocall_t*, pms);
	ms->ms_retval = pthread_wait_timeout_ocall(ms->ms_waiter, ms->ms_timeout);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_pthread_create_ocall(void* pms)
{
	ms_pthread_create_ocall_t* ms = SGX_CAST(ms_pthread_create_ocall_t*, pms);
	ms->ms_retval = pthread_create_ocall(ms->ms_self);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_pthread_wakeup_ocall(void* pms)
{
	ms_pthread_wakeup_ocall_t* ms = SGX_CAST(ms_pthread_wakeup_ocall_t*, pms);
	ms->ms_retval = pthread_wakeup_ocall(ms->ms_waiter);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sysconf_ocall(void* pms)
{
	ms_u_sysconf_ocall_t* ms = SGX_CAST(ms_u_sysconf_ocall_t*, pms);
	ms->ms_retval = u_sysconf_ocall(ms->ms_error, ms->ms_name);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_prctl_ocall(void* pms)
{
	ms_u_prctl_ocall_t* ms = SGX_CAST(ms_u_prctl_ocall_t*, pms);
	ms->ms_retval = u_prctl_ocall(ms->ms_error, ms->ms_option, ms->ms_arg2, ms->ms_arg3, ms->ms_arg4, ms->ms_arg5);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sched_setaffinity_ocall(void* pms)
{
	ms_u_sched_setaffinity_ocall_t* ms = SGX_CAST(ms_u_sched_setaffinity_ocall_t*, pms);
	ms->ms_retval = u_sched_setaffinity_ocall(ms->ms_error, ms->ms_pid, ms->ms_cpusetsize, ms->ms_mask);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sched_getaffinity_ocall(void* pms)
{
	ms_u_sched_getaffinity_ocall_t* ms = SGX_CAST(ms_u_sched_getaffinity_ocall_t*, pms);
	ms->ms_retval = u_sched_getaffinity_ocall(ms->ms_error, ms->ms_pid, ms->ms_cpusetsize, ms->ms_mask);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_sched_yield_ocall(void* pms)
{
	ms_u_sched_yield_ocall_t* ms = SGX_CAST(ms_u_sched_yield_ocall_t*, pms);
	ms->ms_retval = u_sched_yield_ocall(ms->ms_error);

	return SGX_SUCCESS;
}

static sgx_status_t SGX_CDECL Enclave_u_nanosleep_ocall(void* pms)
{
	ms_u_nanosleep_ocall_t* ms = SGX_CAST(ms_u_nanosleep_ocall_t*, pms);
	ms->ms_retval = u_nanosleep_ocall(ms->ms_error, ms->ms_req, ms->ms_rem);

	return SGX_SUCCESS;
}

static const struct {
	size_t nr_ocall;
	void * table[72];
} ocall_table_Enclave = {
	72,
	{
		(void*)Enclave_ocall_cache_to_outside,
		(void*)Enclave_ocall_cache_from_outside,
		(void*)Enclave_sbrk_o,
		(void*)Enclave_u_thread_set_event_ocall,
		(void*)Enclave_u_thread_wait_event_ocall,
		(void*)Enclave_u_thread_set_multiple_events_ocall,
		(void*)Enclave_u_thread_setwait_events_ocall,
		(void*)Enclave_u_clock_gettime_ocall,
		(void*)Enclave_u_read_ocall,
		(void*)Enclave_u_pread64_ocall,
		(void*)Enclave_u_readv_ocall,
		(void*)Enclave_u_preadv64_ocall,
		(void*)Enclave_u_write_ocall,
		(void*)Enclave_u_pwrite64_ocall,
		(void*)Enclave_u_writev_ocall,
		(void*)Enclave_u_pwritev64_ocall,
		(void*)Enclave_u_fcntl_arg0_ocall,
		(void*)Enclave_u_fcntl_arg1_ocall,
		(void*)Enclave_u_ioctl_arg0_ocall,
		(void*)Enclave_u_ioctl_arg1_ocall,
		(void*)Enclave_u_close_ocall,
		(void*)Enclave_u_malloc_ocall,
		(void*)Enclave_u_free_ocall,
		(void*)Enclave_u_mmap_ocall,
		(void*)Enclave_u_munmap_ocall,
		(void*)Enclave_u_msync_ocall,
		(void*)Enclave_u_mprotect_ocall,
		(void*)Enclave_u_open_ocall,
		(void*)Enclave_u_open64_ocall,
		(void*)Enclave_u_fstat_ocall,
		(void*)Enclave_u_fstat64_ocall,
		(void*)Enclave_u_stat_ocall,
		(void*)Enclave_u_stat64_ocall,
		(void*)Enclave_u_lstat_ocall,
		(void*)Enclave_u_lstat64_ocall,
		(void*)Enclave_u_lseek_ocall,
		(void*)Enclave_u_lseek64_ocall,
		(void*)Enclave_u_ftruncate_ocall,
		(void*)Enclave_u_ftruncate64_ocall,
		(void*)Enclave_u_truncate_ocall,
		(void*)Enclave_u_truncate64_ocall,
		(void*)Enclave_u_fsync_ocall,
		(void*)Enclave_u_fdatasync_ocall,
		(void*)Enclave_u_fchmod_ocall,
		(void*)Enclave_u_unlink_ocall,
		(void*)Enclave_u_link_ocall,
		(void*)Enclave_u_rename_ocall,
		(void*)Enclave_u_chmod_ocall,
		(void*)Enclave_u_readlink_ocall,
		(void*)Enclave_u_symlink_ocall,
		(void*)Enclave_u_realpath_ocall,
		(void*)Enclave_u_mkdir_ocall,
		(void*)Enclave_u_rmdir_ocall,
		(void*)Enclave_u_opendir_ocall,
		(void*)Enclave_u_readdir64_r_ocall,
		(void*)Enclave_u_closedir_ocall,
		(void*)Enclave_u_dirfd_ocall,
		(void*)Enclave_u_fstatat64_ocall,
		(void*)Enclave_sgx_oc_cpuidex,
		(void*)Enclave_sgx_thread_wait_untrusted_event_ocall,
		(void*)Enclave_sgx_thread_set_untrusted_event_ocall,
		(void*)Enclave_sgx_thread_setwait_untrusted_events_ocall,
		(void*)Enclave_sgx_thread_set_multiple_untrusted_events_ocall,
		(void*)Enclave_pthread_wait_timeout_ocall,
		(void*)Enclave_pthread_create_ocall,
		(void*)Enclave_pthread_wakeup_ocall,
		(void*)Enclave_u_sysconf_ocall,
		(void*)Enclave_u_prctl_ocall,
		(void*)Enclave_u_sched_setaffinity_ocall,
		(void*)Enclave_u_sched_getaffinity_ocall,
		(void*)Enclave_u_sched_yield_ocall,
		(void*)Enclave_u_nanosleep_ocall,
	}
};
sgx_status_t secure_execute_pre(sgx_enclave_id_t eid, uint64_t tid, uint8_t* op_ids, uint8_t* part_nums, struct dep_info_t dep_info)
{
	sgx_status_t status;
	ms_secure_execute_pre_t ms;
	ms.ms_tid = tid;
	ms.ms_op_ids = op_ids;
	ms.ms_part_nums = part_nums;
	ms.ms_dep_info = dep_info;
	status = sgx_ecall(eid, 0, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t secure_execute(sgx_enclave_id_t eid, size_t* retval, uint64_t tid, size_t stage_id, uint8_t* rdd_ids, uint8_t* op_ids, uint8_t* part_ids, struct cache_meta_t cache_meta, struct dep_info_t dep_info, struct input_t input, uint8_t* captured_vars, size_t* addi_fields)
{
	sgx_status_t status;
	ms_secure_execute_t ms;
	ms.ms_tid = tid;
	ms.ms_stage_id = stage_id;
	ms.ms_rdd_ids = rdd_ids;
	ms.ms_op_ids = op_ids;
	ms.ms_part_ids = part_ids;
	ms.ms_cache_meta = cache_meta;
	ms.ms_dep_info = dep_info;
	ms.ms_input = input;
	ms.ms_captured_vars = captured_vars;
	ms.ms_addi_fields = addi_fields;
	status = sgx_ecall(eid, 1, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t free_res_enc(sgx_enclave_id_t eid, struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* data, uint8_t* marks)
{
	sgx_status_t status;
	ms_free_res_enc_t ms;
	ms.ms_op_id = op_id;
	ms.ms_dep_info = dep_info;
	ms.ms_data = data;
	ms.ms_marks = marks;
	status = sgx_ecall(eid, 2, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t priv_free_res_enc(sgx_enclave_id_t eid, struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* data, uint8_t* marks)
{
	sgx_status_t status;
	ms_priv_free_res_enc_t ms;
	ms.ms_op_id = op_id;
	ms.ms_dep_info = dep_info;
	ms.ms_data = data;
	ms.ms_marks = marks;
	status = sgx_ecall(eid, 3, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t get_sketch(sgx_enclave_id_t eid, struct op_id_t op_id, struct dep_info_t dep_info, uint8_t* p_buf, uint8_t* p_data_enc)
{
	sgx_status_t status;
	ms_get_sketch_t ms;
	ms.ms_op_id = op_id;
	ms.ms_dep_info = dep_info;
	ms.ms_p_buf = p_buf;
	ms.ms_p_data_enc = p_data_enc;
	status = sgx_ecall(eid, 4, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t clone_out(sgx_enclave_id_t eid, struct op_id_t op_id, struct dep_info_t dep_info, size_t p_out, uint8_t* p_data_enc)
{
	sgx_status_t status;
	ms_clone_out_t ms;
	ms.ms_op_id = op_id;
	ms.ms_dep_info = dep_info;
	ms.ms_p_out = p_out;
	ms.ms_p_data_enc = p_data_enc;
	status = sgx_ecall(eid, 5, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t randomize_in_place(sgx_enclave_id_t eid, size_t* retval, struct op_id_t op_id, uint8_t* input, uint64_t seed, uint8_t is_some, uint64_t num)
{
	sgx_status_t status;
	ms_randomize_in_place_t ms;
	ms.ms_op_id = op_id;
	ms.ms_input = input;
	ms.ms_seed = seed;
	ms.ms_is_some = is_some;
	ms.ms_num = num;
	status = sgx_ecall(eid, 6, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t set_sampler(sgx_enclave_id_t eid, struct op_id_t op_id, uint8_t with_replacement, double fraction)
{
	sgx_status_t status;
	ms_set_sampler_t ms;
	ms.ms_op_id = op_id;
	ms.ms_with_replacement = with_replacement;
	ms.ms_fraction = fraction;
	status = sgx_ecall(eid, 7, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t etake(sgx_enclave_id_t eid, size_t* retval, struct op_id_t op_id, uint8_t* input, size_t should_take, size_t* have_take)
{
	sgx_status_t status;
	ms_etake_t ms;
	ms.ms_op_id = op_id;
	ms.ms_input = input;
	ms.ms_should_take = should_take;
	ms.ms_have_take = have_take;
	status = sgx_ecall(eid, 8, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t tail_compute(sgx_enclave_id_t eid, size_t* retval, uint8_t* input)
{
	sgx_status_t status;
	ms_tail_compute_t ms;
	ms.ms_input = input;
	status = sgx_ecall(eid, 9, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t free_tail_info(sgx_enclave_id_t eid, uint8_t* input)
{
	sgx_status_t status;
	ms_free_tail_info_t ms;
	ms.ms_input = input;
	status = sgx_ecall(eid, 10, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t clear_cache(sgx_enclave_id_t eid)
{
	sgx_status_t status;
	status = sgx_ecall(eid, 11, &ocall_table_Enclave, NULL);
	return status;
}

sgx_status_t pre_touching(sgx_enclave_id_t eid, size_t* retval, uint8_t zero)
{
	sgx_status_t status;
	ms_pre_touching_t ms;
	ms.ms_zero = zero;
	status = sgx_ecall(eid, 12, &ocall_table_Enclave, &ms);
	if (status == SGX_SUCCESS && retval) *retval = ms.ms_retval;
	return status;
}

sgx_status_t t_global_init_ecall(sgx_enclave_id_t eid, uint64_t id, const uint8_t* path, size_t len)
{
	sgx_status_t status;
	ms_t_global_init_ecall_t ms;
	ms.ms_id = id;
	ms.ms_path = path;
	ms.ms_len = len;
	status = sgx_ecall(eid, 13, &ocall_table_Enclave, &ms);
	return status;
}

sgx_status_t t_global_exit_ecall(sgx_enclave_id_t eid)
{
	sgx_status_t status;
	status = sgx_ecall(eid, 14, &ocall_table_Enclave, NULL);
	return status;
}

