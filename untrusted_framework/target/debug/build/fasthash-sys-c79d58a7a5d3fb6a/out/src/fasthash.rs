/* automatically generated by rust-bindgen */

#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct pair<_T1, _T2> {
    pub first: _T1,
    pub second: _T2,
    pub _phantom_0: ::std::marker::PhantomData<::std::cell::UnsafeCell<_T1>>,
    pub _phantom_1: ::std::marker::PhantomData<::std::cell::UnsafeCell<_T2>>,
}
pub type pair_first_type<_T1> = _T1;
pub type pair_second_type<_T2> = _T2;
pub type pair__PCCP = u8;
pub type pair__PCCFP = u8;
pub type __uint8_t = ::std::os::raw::c_uchar;
pub type __uint32_t = ::std::os::raw::c_uint;
pub type __uint64_t = ::std::os::raw::c_ulong;
pub type uint32 = u32;
pub type uint64 = u64;
pub type uint128 = pair<uint64, uint64>;
extern "C" {
    #[link_name = "\u{1}_Z18CityHash32WithSeedPKcmj"]
    pub fn CityHash32WithSeed(
        buf: *const ::std::os::raw::c_char,
        len: usize,
        seed: uint32,
    ) -> uint32;
}
extern "C" {
    #[link_name = "\u{1}_Z10CityHash64PKcm"]
    pub fn CityHash64(buf: *const ::std::os::raw::c_char, len: usize) -> uint64;
}
extern "C" {
    #[link_name = "\u{1}_Z18CityHash64WithSeedPKcmm"]
    pub fn CityHash64WithSeed(
        buf: *const ::std::os::raw::c_char,
        len: usize,
        seed: uint64,
    ) -> uint64;
}
extern "C" {
    #[link_name = "\u{1}_Z19CityHash64WithSeedsPKcmmm"]
    pub fn CityHash64WithSeeds(
        buf: *const ::std::os::raw::c_char,
        len: usize,
        seed0: uint64,
        seed1: uint64,
    ) -> uint64;
}
extern "C" {
    #[link_name = "\u{1}_Z11CityHash128PKcm"]
    pub fn CityHash128(s: *const ::std::os::raw::c_char, len: usize) -> uint128;
}
extern "C" {
    #[link_name = "\u{1}_Z19CityHash128WithSeedPKcmSt4pairImmE"]
    pub fn CityHash128WithSeed(
        s: *const ::std::os::raw::c_char,
        len: usize,
        seed: uint128,
    ) -> uint128;
}
extern "C" {
    #[link_name = "\u{1}_Z14CityHashCrc128PKcm"]
    pub fn CityHashCrc128(s: *const ::std::os::raw::c_char, len: usize) -> uint128;
}
extern "C" {
    #[link_name = "\u{1}_Z22CityHashCrc128WithSeedPKcmSt4pairImmE"]
    pub fn CityHashCrc128WithSeed(
        s: *const ::std::os::raw::c_char,
        len: usize,
        seed: uint128,
    ) -> uint128;
}
extern "C" {
    #[link_name = "\u{1}_Z14CityHashCrc256PKcmPm"]
    pub fn CityHashCrc256(s: *const ::std::os::raw::c_char, len: usize, result: *mut uint64);
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct uint128_c_t {
    pub a: u64,
    pub b: u64,
}
#[test]
fn bindgen_test_layout_uint128_c_t() {
    assert_eq!(
        ::std::mem::size_of::<uint128_c_t>(),
        16usize,
        concat!("Size of: ", stringify!(uint128_c_t))
    );
    assert_eq!(
        ::std::mem::align_of::<uint128_c_t>(),
        8usize,
        concat!("Alignment of ", stringify!(uint128_c_t))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<uint128_c_t>())).a as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(uint128_c_t),
            "::",
            stringify!(a)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<uint128_c_t>())).b as *const _ as usize },
        8usize,
        concat!(
            "Offset of field: ",
            stringify!(uint128_c_t),
            "::",
            stringify!(b)
        )
    );
}
extern "C" {
    pub fn farmhash(s: *const ::std::os::raw::c_char, len: usize) -> usize;
}
extern "C" {
    pub fn farmhash32(s: *const ::std::os::raw::c_char, len: usize) -> u32;
}
extern "C" {
    pub fn farmhash32_with_seed(s: *const ::std::os::raw::c_char, len: usize, seed: u32) -> u32;
}
extern "C" {
    pub fn farmhash64(s: *const ::std::os::raw::c_char, len: usize) -> u64;
}
extern "C" {
    pub fn farmhash64_with_seed(s: *const ::std::os::raw::c_char, len: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn farmhash64_with_seeds(
        s: *const ::std::os::raw::c_char,
        len: usize,
        seed0: u64,
        seed1: u64,
    ) -> u64;
}
extern "C" {
    pub fn farmhash128(s: *const ::std::os::raw::c_char, len: usize) -> uint128_c_t;
}
extern "C" {
    pub fn farmhash128_with_seed(
        s: *const ::std::os::raw::c_char,
        len: usize,
        seed: uint128_c_t,
    ) -> uint128_c_t;
}
extern "C" {
    pub fn farmhash_fingerprint32(s: *const ::std::os::raw::c_char, len: usize) -> u32;
}
extern "C" {
    pub fn farmhash_fingerprint64(s: *const ::std::os::raw::c_char, len: usize) -> u64;
}
extern "C" {
    pub fn farmhash_fingerprint128(s: *const ::std::os::raw::c_char, len: usize) -> uint128_c_t;
}
extern "C" {
    #[link_name = "\u{1}_Z13metrohash64_1PKhmjPh"]
    pub fn metrohash64_1(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z13metrohash64_2PKhmjPh"]
    pub fn metrohash64_2(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z16metrohash64crc_1PKhmjPh"]
    pub fn metrohash64crc_1(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z16metrohash64crc_2PKhmjPh"]
    pub fn metrohash64crc_2(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z14metrohash128_1PKhmjPh"]
    pub fn metrohash128_1(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z14metrohash128_2PKhmjPh"]
    pub fn metrohash128_2(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z17metrohash128crc_1PKhmjPh"]
    pub fn metrohash128crc_1(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z17metrohash128crc_2PKhmjPh"]
    pub fn metrohash128crc_2(key: *const u8, len: u64, seed: u32, out: *mut u8);
}
extern "C" {
    #[link_name = "\u{1}_Z11MurmurHash1PKvij"]
    pub fn MurmurHash1(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z18MurmurHash1AlignedPKvij"]
    pub fn MurmurHash1Aligned(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z11MurmurHash2PKvij"]
    pub fn MurmurHash2(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z13MurmurHash64APKvim"]
    pub fn MurmurHash64A(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u64,
    ) -> u64;
}
extern "C" {
    #[link_name = "\u{1}_Z13MurmurHash64BPKvim"]
    pub fn MurmurHash64B(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u64,
    ) -> u64;
}
extern "C" {
    #[link_name = "\u{1}_Z12MurmurHash2APKvij"]
    pub fn MurmurHash2A(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z18MurmurHashNeutral2PKvij"]
    pub fn MurmurHashNeutral2(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z18MurmurHashAligned2PKvij"]
    pub fn MurmurHashAligned2(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z18MurmurHash3_x86_32PKvijPv"]
    pub fn MurmurHash3_x86_32(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
        out: *mut ::std::os::raw::c_void,
    );
}
extern "C" {
    #[link_name = "\u{1}_Z19MurmurHash3_x86_128PKvijPv"]
    pub fn MurmurHash3_x86_128(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
        out: *mut ::std::os::raw::c_void,
    );
}
extern "C" {
    #[link_name = "\u{1}_Z19MurmurHash3_x64_128PKvijPv"]
    pub fn MurmurHash3_x64_128(
        key: *const ::std::os::raw::c_void,
        len: ::std::os::raw::c_int,
        seed: u32,
        out: *mut ::std::os::raw::c_void,
    );
}
#[repr(C)]
#[derive(Copy, Clone)]
pub union t1ha_state256 {
    pub bytes: [u8; 32usize],
    pub u32: [u32; 8usize],
    pub u64: [u64; 4usize],
    pub n: t1ha_state256__bindgen_ty_1,
    _bindgen_union_align: [u64; 4usize],
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct t1ha_state256__bindgen_ty_1 {
    pub a: u64,
    pub b: u64,
    pub c: u64,
    pub d: u64,
}
#[test]
fn bindgen_test_layout_t1ha_state256__bindgen_ty_1() {
    assert_eq!(
        ::std::mem::size_of::<t1ha_state256__bindgen_ty_1>(),
        32usize,
        concat!("Size of: ", stringify!(t1ha_state256__bindgen_ty_1))
    );
    assert_eq!(
        ::std::mem::align_of::<t1ha_state256__bindgen_ty_1>(),
        8usize,
        concat!("Alignment of ", stringify!(t1ha_state256__bindgen_ty_1))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256__bindgen_ty_1>())).a as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256__bindgen_ty_1),
            "::",
            stringify!(a)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256__bindgen_ty_1>())).b as *const _ as usize },
        8usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256__bindgen_ty_1),
            "::",
            stringify!(b)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256__bindgen_ty_1>())).c as *const _ as usize },
        16usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256__bindgen_ty_1),
            "::",
            stringify!(c)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256__bindgen_ty_1>())).d as *const _ as usize },
        24usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256__bindgen_ty_1),
            "::",
            stringify!(d)
        )
    );
}
#[test]
fn bindgen_test_layout_t1ha_state256() {
    assert_eq!(
        ::std::mem::size_of::<t1ha_state256>(),
        32usize,
        concat!("Size of: ", stringify!(t1ha_state256))
    );
    assert_eq!(
        ::std::mem::align_of::<t1ha_state256>(),
        8usize,
        concat!("Alignment of ", stringify!(t1ha_state256))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256>())).bytes as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256),
            "::",
            stringify!(bytes)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256>())).u32 as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256),
            "::",
            stringify!(u32)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256>())).u64 as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256),
            "::",
            stringify!(u64)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_state256>())).n as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_state256),
            "::",
            stringify!(n)
        )
    );
}
pub type t1ha_state256_t = t1ha_state256;
#[repr(C)]
#[derive(Copy, Clone)]
pub struct t1ha_context {
    pub state: t1ha_state256_t,
    pub buffer: t1ha_state256_t,
    pub partial: usize,
    pub total: u64,
    pub __bindgen_padding_0: [u64; 2usize],
}
#[test]
fn bindgen_test_layout_t1ha_context() {
    assert_eq!(
        ::std::mem::size_of::<t1ha_context>(),
        96usize,
        concat!("Size of: ", stringify!(t1ha_context))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_context>())).state as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_context),
            "::",
            stringify!(state)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_context>())).buffer as *const _ as usize },
        32usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_context),
            "::",
            stringify!(buffer)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_context>())).partial as *const _ as usize },
        64usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_context),
            "::",
            stringify!(partial)
        )
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<t1ha_context>())).total as *const _ as usize },
        72usize,
        concat!(
            "Offset of field: ",
            stringify!(t1ha_context),
            "::",
            stringify!(total)
        )
    );
}
pub type t1ha_context_t = t1ha_context;
extern "C" {
    pub fn t1ha2_atonce(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha2_atonce128(
        extra_result: *mut u64,
        data: *const ::std::os::raw::c_void,
        length: usize,
        seed: u64,
    ) -> u64;
}
extern "C" {
    pub fn t1ha2_init(ctx: *mut t1ha_context_t, seed_x: u64, seed_y: u64);
}
extern "C" {
    pub fn t1ha2_update(
        ctx: *mut t1ha_context_t,
        data: *const ::std::os::raw::c_void,
        length: usize,
    );
}
extern "C" {
    pub fn t1ha2_final(ctx: *mut t1ha_context_t, extra_result: *mut u64) -> u64;
}
extern "C" {
    pub fn t1ha1_le(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha1_be(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha0_32le(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha0_32be(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha0_ia32aes_noavx(
        data: *const ::std::os::raw::c_void,
        length: usize,
        seed: u64,
    ) -> u64;
}
extern "C" {
    pub fn t1ha0_ia32aes_avx(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
extern "C" {
    pub fn t1ha0_ia32aes_avx2(data: *const ::std::os::raw::c_void, length: usize, seed: u64)
        -> u64;
}
extern "C" {
    pub fn t1ha0(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
pub const XXH_errorcode_XXH_OK: XXH_errorcode = 0;
pub const XXH_errorcode_XXH_ERROR: XXH_errorcode = 1;
/// Type
pub type XXH_errorcode = u32;
extern "C" {
    /// Simple Hash Functions
    pub fn XXH32(
        input: *const ::std::os::raw::c_void,
        length: usize,
        seed: ::std::os::raw::c_uint,
    ) -> ::std::os::raw::c_uint;
}
extern "C" {
    pub fn XXH64(
        input: *const ::std::os::raw::c_void,
        length: usize,
        seed: ::std::os::raw::c_ulonglong,
    ) -> ::std::os::raw::c_ulonglong;
}
/// Advanced Hash Functions
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct XXH32_state_t {
    pub ll: [::std::os::raw::c_longlong; 6usize],
}
#[test]
fn bindgen_test_layout_XXH32_state_t() {
    assert_eq!(
        ::std::mem::size_of::<XXH32_state_t>(),
        48usize,
        concat!("Size of: ", stringify!(XXH32_state_t))
    );
    assert_eq!(
        ::std::mem::align_of::<XXH32_state_t>(),
        8usize,
        concat!("Alignment of ", stringify!(XXH32_state_t))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<XXH32_state_t>())).ll as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(XXH32_state_t),
            "::",
            stringify!(ll)
        )
    );
}
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct XXH64_state_t {
    pub ll: [::std::os::raw::c_longlong; 11usize],
}
#[test]
fn bindgen_test_layout_XXH64_state_t() {
    assert_eq!(
        ::std::mem::size_of::<XXH64_state_t>(),
        88usize,
        concat!("Size of: ", stringify!(XXH64_state_t))
    );
    assert_eq!(
        ::std::mem::align_of::<XXH64_state_t>(),
        8usize,
        concat!("Alignment of ", stringify!(XXH64_state_t))
    );
    assert_eq!(
        unsafe { &(*(::std::ptr::null::<XXH64_state_t>())).ll as *const _ as usize },
        0usize,
        concat!(
            "Offset of field: ",
            stringify!(XXH64_state_t),
            "::",
            stringify!(ll)
        )
    );
}
extern "C" {
    pub fn XXH32_createState() -> *mut XXH32_state_t;
}
extern "C" {
    pub fn XXH32_freeState(statePtr: *mut XXH32_state_t) -> XXH_errorcode;
}
extern "C" {
    pub fn XXH64_createState() -> *mut XXH64_state_t;
}
extern "C" {
    pub fn XXH64_freeState(statePtr: *mut XXH64_state_t) -> XXH_errorcode;
}
extern "C" {
    pub fn XXH32_reset(statePtr: *mut XXH32_state_t, seed: ::std::os::raw::c_uint)
        -> XXH_errorcode;
}
extern "C" {
    pub fn XXH32_update(
        statePtr: *mut XXH32_state_t,
        input: *const ::std::os::raw::c_void,
        length: usize,
    ) -> XXH_errorcode;
}
extern "C" {
    pub fn XXH32_digest(statePtr: *const XXH32_state_t) -> ::std::os::raw::c_uint;
}
extern "C" {
    pub fn XXH64_reset(
        statePtr: *mut XXH64_state_t,
        seed: ::std::os::raw::c_ulonglong,
    ) -> XXH_errorcode;
}
extern "C" {
    pub fn XXH64_update(
        statePtr: *mut XXH64_state_t,
        input: *const ::std::os::raw::c_void,
        length: usize,
    ) -> XXH_errorcode;
}
extern "C" {
    pub fn XXH64_digest(statePtr: *const XXH64_state_t) -> ::std::os::raw::c_ulonglong;
}
extern "C" {
    #[link_name = "\u{1}_Z28farmhash_fingerprint_uint12811uint128_c_t"]
    pub fn farmhash_fingerprint_uint128(x: uint128_c_t) -> u64;
}
extern "C" {
    #[link_name = "\u{1}_Z27farmhash_fingerprint_uint64m"]
    pub fn farmhash_fingerprint_uint64(x: u64) -> u64;
}
extern "C" {
    #[link_name = "\u{1}_Z7lookup3PKvij"]
    pub fn lookup3(
        key: *const ::std::os::raw::c_void,
        length: ::std::os::raw::c_int,
        initval: u32,
    ) -> u32;
}
extern "C" {
    #[link_name = "\u{1}_Z9mum_hash_PKvmm"]
    pub fn mum_hash_(key: *const ::std::os::raw::c_void, len: usize, seed: u64) -> u64;
}
extern "C" {
    #[link_name = "\u{1}_Z16SpookyHasherHashPKvmPmS1_"]
    pub fn SpookyHasherHash(
        message: *const ::std::os::raw::c_void,
        length: usize,
        hash1: *mut uint64,
        hash2: *mut uint64,
    );
}
extern "C" {
    #[link_name = "\u{1}_Z15SpookyHasherNewv"]
    pub fn SpookyHasherNew() -> *mut ::std::os::raw::c_void;
}
extern "C" {
    #[link_name = "\u{1}_Z16SpookyHasherFreePv"]
    pub fn SpookyHasherFree(h: *mut ::std::os::raw::c_void);
}
extern "C" {
    #[link_name = "\u{1}_Z16SpookyHasherInitPvmm"]
    pub fn SpookyHasherInit(h: *mut ::std::os::raw::c_void, seed1: uint64, seed2: uint64);
}
extern "C" {
    #[link_name = "\u{1}_Z18SpookyHasherUpdatePvPKvm"]
    pub fn SpookyHasherUpdate(
        h: *mut ::std::os::raw::c_void,
        message: *const ::std::os::raw::c_void,
        length: usize,
    );
}
extern "C" {
    #[link_name = "\u{1}_Z17SpookyHasherFinalPvPmS0_"]
    pub fn SpookyHasherFinal(
        h: *mut ::std::os::raw::c_void,
        hash1: *mut uint64,
        hash2: *mut uint64,
    );
}
extern "C" {
    #[link_name = "\u{1}_Z8t1ha0_64PKvmm"]
    pub fn t1ha0_64(data: *const ::std::os::raw::c_void, length: usize, seed: u64) -> u64;
}
#[test]
fn __bindgen_test_layout_pair_open0_uint64_uint64_close0_instantiation() {
    assert_eq!(
        ::std::mem::size_of::<pair<uint64, uint64>>(),
        16usize,
        concat!(
            "Size of template specialization: ",
            stringify ! ( pair < uint64 , uint64 > )
        )
    );
    assert_eq!(
        ::std::mem::align_of::<pair<uint64, uint64>>(),
        8usize,
        concat!(
            "Alignment of template specialization: ",
            stringify ! ( pair < uint64 , uint64 > )
        )
    );
}
