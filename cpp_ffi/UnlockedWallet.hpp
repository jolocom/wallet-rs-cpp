// Automatically generated by flapigen
#pragma once

//for assert
#include <cassert>
//for std::abort
#include <cstdlib>
//for std::move
#include <utility>
//for std::conditional
#include <type_traits>

#include "rust_str.h"
#include <string_view>
#include "c_KeyType.h"
#include <stdint.h>
#include "VecOfString.hpp"
#include "c_VecOfString.h"
#include "ContentEntity.hpp"
#include "c_ContentEntity.h"
#include "rust_result4232mut3232c_voidCRustString.h"
#include <variant>
#include "Content.hpp"
#include "c_Content.h"
#include "rust_option.h"
#include <optional>
#include "RustForeignVecContentEntity.h"
#include "rust_vec.h"
#include "CRustSliceu8.h"
#include "rust_vec_u8.h"
#include "rust_resultCRustVecu8CRustString.h"
#include "LockedWallet.hpp"
#include "c_LockedWallet.h"

#include "c_UnlockedWallet.h"

namespace rust {

template<bool>
class UnlockedWalletWrapper;
using UnlockedWallet = UnlockedWalletWrapper<true>;
using UnlockedWalletRef = UnlockedWalletWrapper<false>;


template<bool OWN_DATA>
class UnlockedWalletWrapper {
public:
    using value_type = UnlockedWalletWrapper<true>;
    friend class UnlockedWalletWrapper<true>;
    friend class UnlockedWalletWrapper<false>;

    using SelfType = typename std::conditional<OWN_DATA, UnlockedWalletOpaque *, const UnlockedWalletOpaque *>::type;
    using CForeignType = UnlockedWalletOpaque;

    UnlockedWalletWrapper(UnlockedWalletWrapper &&o) noexcept: self_(o.self_)
    {
        o.self_ = nullptr;
    }
    UnlockedWalletWrapper &operator=(UnlockedWalletWrapper &&o) noexcept
    {
        assert(this != &o);
        free_mem(this->self_);
        self_ = o.self_;
        o.self_ = nullptr;
        return *this;
    }
    explicit UnlockedWalletWrapper(SelfType o) noexcept: self_(o) {}
    UnlockedWalletOpaque *release() noexcept
    {
        UnlockedWalletOpaque *ret = self_;
        self_ = nullptr;
        return ret;
    }
    explicit operator SelfType() const noexcept { return self_; }
    UnlockedWalletWrapper<false> as_rref() const noexcept { return UnlockedWalletWrapper<false>{ self_ }; }
    const UnlockedWalletWrapper<true> &as_cref() const noexcept { return reinterpret_cast<const UnlockedWalletWrapper<true> &>(*this); }

    UnlockedWalletWrapper(const UnlockedWalletWrapper&) = delete;
    UnlockedWalletWrapper &operator=(const UnlockedWalletWrapper&) = delete;

    UnlockedWalletWrapper(std::string_view a0) noexcept
    {

        this->self_ = UnlockedWallet_new(CRustStrView{ a0.data(), a0.size() });
        if (this->self_ == nullptr) {
            std::abort();
        }
    }

    std::variant<ContentEntity, RustString> new_key(KeyType key_type, VecOfString key_controller) noexcept;

    std::optional<ContentEntity> import_content(const Content & content) noexcept;

    std::optional<ContentEntity> set_content(std::string_view cref, Content content) noexcept;

    std::optional<ContentEntity> get_key(std::string_view key_ref) const noexcept;

    std::optional<ContentEntity> get_key_by_controller(std::string_view controller) const noexcept;

    std::optional<void> set_key_controller(std::string_view key_ref, std::string_view controller) noexcept;

    RustForeignVecContentEntity get_keys() const noexcept;

    std::variant<RustVecu8, RustString> sign_raw(std::string_view key_ref, RustSlice<const uint8_t> data) const noexcept;

    std::variant<RustVecu8, RustString> decrypt(std::string_view key_ref, RustSlice<const uint8_t> data, std::optional<RustSlice<const uint8_t>> aad) const noexcept;

    std::variant<RustVecu8, RustString> ecdh_key_agreement(std::string_view key_ref, RustSlice<const uint8_t> key) const noexcept;

    std::variant<LockedWallet, RustString> lock(RustSlice<const uint8_t> a0) const noexcept;

private:
   static void free_mem(SelfType &p) noexcept
   {
        if (OWN_DATA && p != nullptr) {
            UnlockedWallet_delete(p);
        }
        p = nullptr;
   }
public:
    ~UnlockedWalletWrapper() noexcept
    {
        free_mem(this->self_);
    }

private:
    SelfType self_;
};


    template<bool OWN_DATA>
    inline std::variant<ContentEntity, RustString> UnlockedWalletWrapper<OWN_DATA>::new_key(KeyType key_type, VecOfString key_controller) noexcept
    {

        struct CRustResult4232mut3232c_voidCRustString ret = UnlockedWallet_new_key(this->self_, static_cast<uint32_t>(key_type), key_controller.release());
        return ret.is_ok != 0 ?
              std::variant<ContentEntity, RustString> { ContentEntity(static_cast<ContentEntityOpaque *>(ret.data.ok)) } :
              std::variant<ContentEntity, RustString> { RustString{ret.data.err} };
    }

    template<bool OWN_DATA>
    inline std::optional<ContentEntity> UnlockedWalletWrapper<OWN_DATA>::import_content(const Content & content) noexcept
    {

        struct CRustOption4232mut3232c_void ret = UnlockedWallet_import_content(this->self_, static_cast<const ContentOpaque *>(content));
        return (ret.is_some != 0) ? std::optional<ContentEntity>(ContentEntity(static_cast<ContentEntityOpaque *>(ret.val.data))) : std::optional<ContentEntity>();
    }

    template<bool OWN_DATA>
    inline std::optional<ContentEntity> UnlockedWalletWrapper<OWN_DATA>::set_content(std::string_view cref, Content content) noexcept
    {

        struct CRustOption4232mut3232c_void ret = UnlockedWallet_set_content(this->self_, CRustStrView{ cref.data(), cref.size() }, content.release());
        return (ret.is_some != 0) ? std::optional<ContentEntity>(ContentEntity(static_cast<ContentEntityOpaque *>(ret.val.data))) : std::optional<ContentEntity>();
    }

    template<bool OWN_DATA>
    inline std::optional<ContentEntity> UnlockedWalletWrapper<OWN_DATA>::get_key(std::string_view key_ref) const noexcept
    {

        struct CRustOption4232mut3232c_void ret = UnlockedWallet_get_key(this->self_, CRustStrView{ key_ref.data(), key_ref.size() });
        return (ret.is_some != 0) ? std::optional<ContentEntity>(ContentEntity(static_cast<ContentEntityOpaque *>(ret.val.data))) : std::optional<ContentEntity>();
    }

    template<bool OWN_DATA>
    inline std::optional<ContentEntity> UnlockedWalletWrapper<OWN_DATA>::get_key_by_controller(std::string_view controller) const noexcept
    {

        struct CRustOption4232mut3232c_void ret = UnlockedWallet_get_key_by_controller(this->self_, CRustStrView{ controller.data(), controller.size() });
        return (ret.is_some != 0) ? std::optional<ContentEntity>(ContentEntity(static_cast<ContentEntityOpaque *>(ret.val.data))) : std::optional<ContentEntity>();
    }

    template<bool OWN_DATA>
    inline std::optional<void> UnlockedWalletWrapper<OWN_DATA>::set_key_controller(std::string_view key_ref, std::string_view controller) noexcept
    {

        struct CRustOption4041 ret = UnlockedWallet_set_key_controller(this->self_, CRustStrView{ key_ref.data(), key_ref.size() }, CRustStrView{ controller.data(), controller.size() });
        return (ret.is_some != 0) ? std::optional<void>(ret.val.data) : std::optional<void>();
    }

    template<bool OWN_DATA>
    inline RustForeignVecContentEntity UnlockedWalletWrapper<OWN_DATA>::get_keys() const noexcept
    {

        struct CRustForeignVec ret = UnlockedWallet_get_keys(this->self_);
        return RustForeignVecContentEntity{ret};
    }

    template<bool OWN_DATA>
    inline std::variant<RustVecu8, RustString> UnlockedWalletWrapper<OWN_DATA>::sign_raw(std::string_view key_ref, RustSlice<const uint8_t> data) const noexcept
    {

        struct CRustResultCRustVecu8CRustString ret = UnlockedWallet_sign_raw(this->self_, CRustStrView{ key_ref.data(), key_ref.size() }, data.as_c<CRustSliceu8>());
        return ret.is_ok != 0 ?
              std::variant<RustVecu8, RustString> { RustVecu8{ret.data.ok} } :
              std::variant<RustVecu8, RustString> { RustString{ret.data.err} };
    }

    template<bool OWN_DATA>
    inline std::variant<RustVecu8, RustString> UnlockedWalletWrapper<OWN_DATA>::decrypt(std::string_view key_ref, RustSlice<const uint8_t> data, std::optional<RustSlice<const uint8_t>> aad) const noexcept
    {
        struct CRustOptionCRustSliceu8 a2;
        if (!!aad) {
            a2.val.data = (*aad).as_c<CRustSliceu8>();
            a2.is_some = 1;
        } else {
            a2.is_some = 0;
        }
        struct CRustResultCRustVecu8CRustString ret = UnlockedWallet_decrypt(this->self_, CRustStrView{ key_ref.data(), key_ref.size() }, data.as_c<CRustSliceu8>(), std::move(a2));
        return ret.is_ok != 0 ?
              std::variant<RustVecu8, RustString> { RustVecu8{ret.data.ok} } :
              std::variant<RustVecu8, RustString> { RustString{ret.data.err} };
    }

    template<bool OWN_DATA>
    inline std::variant<RustVecu8, RustString> UnlockedWalletWrapper<OWN_DATA>::ecdh_key_agreement(std::string_view key_ref, RustSlice<const uint8_t> key) const noexcept
    {

        struct CRustResultCRustVecu8CRustString ret = UnlockedWallet_ecdh_key_agreement(this->self_, CRustStrView{ key_ref.data(), key_ref.size() }, key.as_c<CRustSliceu8>());
        return ret.is_ok != 0 ?
              std::variant<RustVecu8, RustString> { RustVecu8{ret.data.ok} } :
              std::variant<RustVecu8, RustString> { RustString{ret.data.err} };
    }

    template<bool OWN_DATA>
    inline std::variant<LockedWallet, RustString> UnlockedWalletWrapper<OWN_DATA>::lock(RustSlice<const uint8_t> a0) const noexcept
    {

        struct CRustResult4232mut3232c_voidCRustString ret = UnlockedWallet_lock(this->self_, a0.as_c<CRustSliceu8>());
        return ret.is_ok != 0 ?
              std::variant<LockedWallet, RustString> { LockedWallet(static_cast<LockedWalletOpaque *>(ret.data.ok)) } :
              std::variant<LockedWallet, RustString> { RustString{ret.data.err} };
    }

} // namespace rust
