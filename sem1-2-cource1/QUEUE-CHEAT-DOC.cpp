
/*

так реализована очередь в std

*/

template <class _Tp, class _Container /*= deque<_Tp>*/>
class _LIBCPP_TEMPLATE_VIS queue
{
public:
    typedef _Container                               container_type;
    typedef typename container_type::value_type      value_type;
    typedef typename container_type::reference       reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type       size_type;
    static_assert((is_same<_Tp, value_type>::value), "" );

protected:
    container_type c;

public:
    _LIBCPP_INLINE_VISIBILITY
    queue()
        _NOEXCEPT_(is_nothrow_default_constructible<container_type>::value)
        : c() {}

    _LIBCPP_INLINE_VISIBILITY
    queue(const queue& __q) : c(__q.c) {}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    _LIBCPP_INLINE_VISIBILITY
    queue(queue&& __q)
        _NOEXCEPT_(is_nothrow_move_constructible<container_type>::value)
        : c(_VSTD::move(__q.c)) {}
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

    _LIBCPP_INLINE_VISIBILITY
    queue& operator=(const queue& __q) {c = __q.c; return *this;}

#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    _LIBCPP_INLINE_VISIBILITY
    queue& operator=(queue&& __q)
        _NOEXCEPT_(is_nothrow_move_assignable<container_type>::value)
        {c = _VSTD::move(__q.c); return *this;}
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

    _LIBCPP_INLINE_VISIBILITY
    explicit queue(const container_type& __c)  : c(__c) {}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    _LIBCPP_INLINE_VISIBILITY
    explicit queue(container_type&& __c) : c(_VSTD::move(__c)) {}
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
    template <class _Alloc>
        _LIBCPP_INLINE_VISIBILITY
        explicit queue(const _Alloc& __a,
                       typename enable_if<uses_allocator<container_type,
                                                         _Alloc>::value>::type* = 0)
            : c(__a) {}
    template <class _Alloc>
        _LIBCPP_INLINE_VISIBILITY
        queue(const queue& __q, const _Alloc& __a,
                       typename enable_if<uses_allocator<container_type,
                                                         _Alloc>::value>::type* = 0)
            : c(__q.c, __a) {}
    template <class _Alloc>
        _LIBCPP_INLINE_VISIBILITY
        queue(const container_type& __c, const _Alloc& __a,
                       typename enable_if<uses_allocator<container_type,
                                                         _Alloc>::value>::type* = 0)
            : c(__c, __a) {}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    template <class _Alloc>
        _LIBCPP_INLINE_VISIBILITY
        queue(container_type&& __c, const _Alloc& __a,
                       typename enable_if<uses_allocator<container_type,
                                                         _Alloc>::value>::type* = 0)
            : c(_VSTD::move(__c), __a) {}
    template <class _Alloc>
        _LIBCPP_INLINE_VISIBILITY
        queue(queue&& __q, const _Alloc& __a,
                       typename enable_if<uses_allocator<container_type,
                                                         _Alloc>::value>::type* = 0)
            : c(_VSTD::move(__q.c), __a) {}

#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES

    _LIBCPP_INLINE_VISIBILITY
    bool      empty() const {return c.empty();}
    _LIBCPP_INLINE_VISIBILITY
    size_type size() const  {return c.size();}

    _LIBCPP_INLINE_VISIBILITY
    reference       front()       {return c.front();}
    _LIBCPP_INLINE_VISIBILITY
    const_reference front() const {return c.front();}
    _LIBCPP_INLINE_VISIBILITY
    reference       back()        {return c.back();}
    _LIBCPP_INLINE_VISIBILITY
    const_reference back() const  {return c.back();}

    _LIBCPP_INLINE_VISIBILITY
    void push(const value_type& __v) {c.push_back(__v);}
#ifndef _LIBCPP_HAS_NO_RVALUE_REFERENCES
    _LIBCPP_INLINE_VISIBILITY
    void push(value_type&& __v)      {c.push_back(_VSTD::move(__v));}
#ifndef _LIBCPP_HAS_NO_VARIADICS
    template <class... _Args>
        _LIBCPP_INLINE_VISIBILITY
#if _LIBCPP_STD_VER > 14
        reference emplace(_Args&&... __args)
            { return c.emplace_back(_VSTD::forward<_Args>(__args)...);}
#else
        void     emplace(_Args&&... __args)
            {        c.emplace_back(_VSTD::forward<_Args>(__args)...);}
#endif
#endif  // _LIBCPP_HAS_NO_VARIADICS
#endif  // _LIBCPP_HAS_NO_RVALUE_REFERENCES
    _LIBCPP_INLINE_VISIBILITY
    void pop() {c.pop_front();}

    _LIBCPP_INLINE_VISIBILITY
    void swap(queue& __q)
        _NOEXCEPT_(__is_nothrow_swappable<container_type>::value)
    {
        using _VSTD::swap;
        swap(c, __q.c);
    }

    template <class _T1, class _C1>
    friend
    _LIBCPP_INLINE_VISIBILITY
    bool
    operator==(const queue<_T1, _C1>& __x,const queue<_T1, _C1>& __y);

    template <class _T1, class _C1>
    friend
    _LIBCPP_INLINE_VISIBILITY
    bool
    operator< (const queue<_T1, _C1>& __x,const queue<_T1, _C1>& __y);
};

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator==(const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return __x.c == __y.c;
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator< (const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return __x.c < __y.c;
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator!=(const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return !(__x == __y);
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator> (const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return __y < __x;
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator>=(const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return !(__x < __y);
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator<=(const queue<_Tp, _Container>& __x,const queue<_Tp, _Container>& __y)
{
    return !(__y < __x);
}

template <class _Tp, class _Container>
inline _LIBCPP_INLINE_VISIBILITY
typename enable_if<
    __is_swappable<_Container>::value,
    void
>::type
swap(queue<_Tp, _Container>& __x, queue<_Tp, _Container>& __y)
    _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y)))
{
    __x.swap(__y);
}

template <class _Tp, class _Container, class _Alloc>
struct _LIBCPP_TEMPLATE_VIS uses_allocator<queue<_Tp, _Container>, _Alloc>
    : public uses_allocator<_Container, _Alloc>
{
};
